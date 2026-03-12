#include <iostream>
#include <vector>
#include <functional>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 3; 
    int total_cells = n * n; 
    
    int dir[5] = {-1, 0, 1, 0, -1};
    
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    int paths_found = 0;

    auto valid = [&](int r, int c) {
        return r >= 0 && r < n && c >= 0 && c < n;
    };

    // DFS with Backtracking
    // r, c: current position
    // count: how many cells we have visited so far
    function<void(int, int, int)> dfs = [&](int r, int c, int count) {
        // 1. Base Case: Reached destination (n-1, n-1)
        if (r == n - 1 && c == n - 1) {
            // Check if we visited ALL cells
            if (count == total_cells) {
                paths_found++;
            }
            return;
        }
        vis[r][c] = true;
        for (int k = 0; k < 4; k++) {
            int nr = r + dir[k];
            int nc = c + dir[k+1];

            if (valid(nr, nc) && !vis[nr][nc]) {
                dfs(nr, nc, count + 1);
            }
        }

        // 4. Backtrack: Unmark cell so other paths can use it
        vis[r][c] = false;
    };

    // Start DFS at (0,0) with count 1 (since we visit the start cell)
    dfs(0, 0, 1);

    cout << paths_found << "\n";

    return 0;
}