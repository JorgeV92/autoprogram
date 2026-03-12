#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        auto brute_force = [&]() {
            int n = grid.size();
            using pii = pair<int,int>;
            vector<pii> zero_cells;
            for (int i = 0; i < n ; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == 0) {
                        zero_cells.push_back({i,j});
                    } 
                }
            }

            if (zero_cells.empty()) {
                return n*n;
            }
        
            vector<pii> dir{{1,0}, {-1,0}, {0, 1}, {0,-1}};
            vector<vector<bool>> visited(n, vector<bool>(n, false));
            int best = 0;

            function<int(int,int)> dfs = [&](int i, int j) {
                if (i < 0 || i >= n || j < 0 || j >= n || visited[i][j] || grid[i][j] != 1) {
                        return 0;
                }
                visited[i][j] = true;
                int size = 1;
                for (const auto& [di, dj] : dir) {
                    int ni = i + di , nj = j + dj;
                    size += dfs(ni, nj);
                }

                return size;
            };
            
            auto print_grid = [&]() {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        cout << " | " << grid[i][j] << " | ";
                    }
                    cout << endl;
                }
            };

            for (auto& [x, y] : zero_cells) {
                grid[x][y] = 1;
                print_grid();
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        if (!visited[i][j])
                            best = max(best, dfs(i, j));
                    }
                }
                visited = vector<vector<bool>>(n, vector<bool>(n, false));
                grid[x][y] = 0;
            }

            return best;
        };

        return brute_force();
    }
};




class Solution2 {
public:

int largestIsland(vector<vector<int>>& grid) {
    n = grid.size();
    g = grid;
    components = vector<vector<int>>(n, vector<int>(n, -1));
    size = vector<int>(n*n+1);
    
    int c = 0;
    int mx_island = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (g[i][j] == 1 && components[i][j] == -1) {
                mx_island = max(mx_island, dfs(i, j, c));
                c++;
             }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (g[i][j] == 0) {
                unordered_set<int> adj_islands;

                for (int k = 0; k < 4; k++) {
                    int ni = i + d[k];
                    int nj = j + d[k+1];
                    
                    if (is_valid(ni, nj) && g[ni][nj] == 1) {
                        adj_islands.insert(components[ni][nj]);
                    }
                }

                int total_size = 1;
                for (int id : adj_islands) {
                    total_size += size[id];
                }

                mx_island = max(mx_island, total_size);
            }
        }
    }

    return mx_island;
}

private:
    vector<vector<int>> g;
    vector<vector<int>> components;
    vector<int> size;
    int n;
    int d[5] = {-1, 0, 1, 0, -1};

    bool is_valid(int r, int c) {
        return (0 <= r && r < n && 0 <= c && c < n);
    }

    int dfs(int r, int c, int cval) {
        components[r][c] = cval;
        size[cval]++;

        for (int k = 0; k < 4; k++) {
            int nr = r + d[k];
            int nc = c + d[k+1];

            if (is_valid(nr, nc) && g[nr][nc] == 1 && components[nr][nc] == -1) {
                dfs(nr, nc, cval);
            }
        }

        return size[cval];
    }


};



class Solution3 {
public:
    int largestIsland(vector<vector<int>> grid) {
        int n = grid.size();
        vector<vector<int>> cmpts(n, vector<int>(n, -1));
        vector<int> size(n*n+1);

        int dir[5] = {-1, 0, 1, 0, -1};

        auto is_valid = [&](int x, int y) {
            return (0 <= x && x < n && 0 <= y < n);
        };

        function<int(int,int,int)> dfs = [&](int r, int c, int cval) -> int {
            cmpts[r][c] = cval;
            size[cval]++;

            for (int k = 0; k < 4; k++) {
                int nr = r + dir[k];
                int nc = c + dir[k+1];

                if (is_valid(nr, nc) && grid[nr][nc] == 1 && cmpts[nr][nc] == -1) {
                    dfs(nr, nc, cval);
                }
            }

            return size[cval];
        };

        int maxIsland = 0;
        int c = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && cmpts[i][j] == -1) {
                    maxIsland = max(maxIsland, dfs(i, j, c));
                    c++;
                } 
            }
        }


        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> adjIslands;

                    for (int k = 0; k < 4; k++) {
                        int ni = i + dir[k];
                        int nj = j + dir[k+1];

                        if (is_valid(ni, nj) && grid[ni][nj] == 1) {
                            adjIslands.insert(cmpts[ni][nj]);
                        }
                    }

                    int total_size = 1;
                    for (int id : adjIslands) {
                        total_size += size[id];
                    }

                    maxIsland = max(maxIsland, total_size);
                }
            }
        }

        return maxIsland;

        // O(N^2) time solution 
    }
}















