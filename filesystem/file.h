#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

#ifndef FILE_H
#define FILE_H

class File {
public:
    File() = default;

    explicit File(std::string path) {
        if (std::filesystem::exists(path)) {
            dir = path;
        } else {
            exit(1);
        }
    }

    bool createFile(const std::string& file_name) {
        std::ofstream file;
        file.open(file_name);
        if (!file.is_open()) {
            std::cout << "Error in creating file!" << std::endl;
            exit(1);
        }
        std::cout << "File created." << std::endl;
    } 

    void setPath(std::string path) {
        if (std::filesystem::exists(path)) {
            dir = path;
        } else {
            std::cout << "Error path does not exists.\n";
            exit(1);
        }
    }
    
private:
    std::filesystem::path dir{};    
};

#endif