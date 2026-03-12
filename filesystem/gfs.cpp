#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <memory>
#include <algorithm>
#include <random>
#include <mutex>
#include <span>
#include <optional>
#include <stdexcept>

constexpr size_t CHUNK_SIZE = 64;

using ChunckHandle = uint64_t;
using ServerID = int;


// Store chucks as local files (simulated in memory).
// Handles read/write requests for data/
class ChunckServer {
public:
    explicit ChunckServer(ServerID id) : id_(id) {}
    ServerID getId() const { return id_; }

    void writeChunck(ChunckHandle handle, size_t offset, std::span<const char> datat) {
        std::lock_guard<std::mutex> lock(mutex_);
        if (chunks_.find(handle) == chunks_.end()) {
            chunks_[handle].resize(CHUNK_SIZE, 0);
        }

        auto& chunkData = chunks_[handle];

        if (offset + data.size() > CHUNK_SIZE) {
            throw std::out_of_range("Write exceeds chuck size");
        }

        std::copy(data.begin(), data.end(), chunkData.begin() + offset);
        std::cout << "[ChunkServer " << id_ << "] Wrote " << data.size() 
                  << " bytes to Chuck " << handle << " at offset " << offset << std::endl;
    }

    void readChuck(ChunckHandle handle, size_t offset, size_t length, std::vector<char>& buffer) {

    }

private:
    ServerID id_;
    std::map<ChunckHandle, std::vector<char>> chunks_;
    std::mutex mutex_;
};

class Master {
public:
    void registerChunckServer(std::shared_ptr<ChunckServer> server) {
        chunckServers_[server->getId()] = server;
    }

    void createFile(const std::string& filename) {
        std::lock_guard<std::mutex> lock(mutex_);
        if (fileNamespace_.contains(filename)) {
            throw std::runtime_error("File already exists");
        }
        fileNamespace_[filename] = {};
        std::cout << "[Master] Created file: " << filename << std::endl;
    }

    // Allocate new chunck for a file.
    // Returns the new handle and the servers where replicas should be stored.
    // Greedy: We just pick the first available server as the replica.
    std::pair<ChunckHandle, std::vector<std::shared_ptr<ChunckServer>>> 
    allocateChunck(const std::string& filename) {
        std::lock_guard<std::mutex> lock(mutex_);
        ChunckHandle newHandle = nextChunckHandle_++;
        fileNamespace_[filename].push_back(newHandle);

        std::vector<std::shared_ptr<ChunckServer>> replicas;
        for (auto& [id, server] : chunckServers_) {
            replicas.push_back(server);
            chunckLocations_[newHandle].push_back(id);
            if (replicas.size() >= 3) break;
        }

        std::cout << "[Master] Allocated Chunck " << newHandle << " for file "<< filename << endl;
        return {newHandle, replicas};
    }

    std::optional<std::pair<ChunckHandle, std::vector<std::shared_ptr<ChunckServer>>>>
    getChunckMetadata(const std::string& filename, size_t chunckIndex) {
        std::lock_guard<std::mutex> lock(mutex_);
        if (!fileNamespace_.contains(filename))
            return std::nullopt;
        
        const auto& chuncks = fileNamespace_[filename];
        if (chunckIndex >= chuncks.size()) 
            return std::nullopt;
        ChunckHandle handle = chuncks[chunckIndex];
        std::vector<std::shared_ptr<ChunckServer>> locations;

        for (ServerID id : chunckLocations_[handle]) {
            if (chunckServers_.contains(id)) {
                locations.push_back(chunckServers_[id]);
            }
        }

        return std::make_pair(handle, locations);
    }

private:
    std::mutex mutex_;
    ChunckHandle nextChunckHandle_ = 1;
    std::map<std::string, std::vector<ChunckHandle>> fileNamespace_;
    std::map<ChunckHandle, std::vector<ServerID>> chunckLocations_;
    std::map<ServerID, std::shared_ptr<ChunckServer>> chunckServers_;
};

class GFSClient {
public:
    explicit GFSClient(std::shared_ptr<Master> master) : master_{master} {}

    // Simple append
    void write(const std::string& filename, size_t offset, const std::string& data) {
        size_t currentOffset = offset;
        size_t bytesWritten = 0;

        while (bytesWritten < data.size()) {
            size_t chunckIndex = currentOffset / CHUNK_SIZE;
            size_t offsetInChunck = currentOffset % CHUNK_SIZE;
            size_t bytesToCopy = std::min(data.size() - bytesWritten, CHUNK_SIZE - offsetInChunck);

            auto metadata = master_->getChunckMetadata(filename, chunckIndex);
            ChunckHandle handle{};
                
            std::vector<std::shared_ptr<ChunckServer>> replicas;

            if (!metadata) {
                auto allocResult = master_->allocateChunck(filename);
                handle = allocResult.first;
                replicas = allocResult.second;
            } else {
                handle = metadata->first;
                replicas = metadata->second;
            }

            std::span<const char> dataSpan(data.data() + bytesWritten, bytesToCopy);

            for (auto& server : replicas) {
                server->writeChunck(handle, offsetInChunck, dataSpan);
            }

            bytesWritten += bytesToCopy;
            currentOffset += bytesToCopy;
        }
    }

    std::string read(const std::string& filename, size_t offset, size_t length) {
        std::string res;
        size_t currentOffset = offset;
        size_t bytesRead = 0;

        while (bytesRead < length) {
            size_t chunckIndex = currentOffset / CHUNK_SIZE;
            size_t offsetInChunck = currentOffset % CHUNK_SIZE;
            size_t bytesToRead = std::min(length - bytesRead, CHUNK_SIZE - offsetInChunck);

            auto metadata = master_->getChunckMetadata(filename, chunckIndex);

            if (!metadata) break; // End of file

            ChunckHandle handle = metadata->first;
            auto& replicas = metadata->second;

            if (replicas.empty()) 
                throw std::runtime_error("No replicas available");

            std::vector<char> buffer;
            replicas[0]->readChuck(handle, offsetInChunck, bytesToRead, buffer);

            res.append(buffer.begin(), buffer.end());
            bytesRead += buffer.size();
            currentOffset += buffer.size();

            if (buffer.size() < bytesToRead) break;
        }

        return res;
    }

private:
    std::shared_ptr<Master> master_;
};

int main() {    

    auto master = std::make_shared<Master>();

    auto cs1 = std::make_shared<ChunckServer>(1);
    auto cs2 = std::make_shared<ChunckServer>(2);
    auto cs3 = std::make_shared<ChunckServer>(3);

    master->registerChunckServer(cs1);
    master->registerChunckServer(cs2);
    master->registerChunckServer(cs3);

    GFSClient client(master);

    // Simulate test
    try {
        std::string filename = "/filesystem/report.txt";

        master->createFile(filename);

        std::string content = "This is a simplified GFS simulation.";
        while (content.size() < 150) 
            content += "Appending data...";
        
        std::cout << "\n----Client Writing Data (" << content.size() << " bytes) ---\n";
        client.write(filename, 0, content);

        std::cout << "\n----Client Reading Data ---\n";
        std::string readBack = client.read(filename, 0, content.size());

        std::cout << "Read Content: " << readBack.substr(0, 50) << "...\n";

        if (content == readBack) {
            std::cout << "SUCCESS: Data integrity verified.\n";
        } else {
            std::cout << "FAILURE: DATA mismatch.\n";
        }

    } catch (const std::exception& e) {
        std::cerr << "Error " << e.what() << std::endl;
    }
 
    return 0;
}
