#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> g;
int d[5] = {-1,0,1,0,-1};
int M, N;

bool valid(int r, int c) {
    return (0 <= r && r < M && 0 <= c && c < N);
}

int dfs(int r, int c) {
    if (!valid(r, c)) return 0;
    g[r][c] = 0;
    int total = 1;
    for (int k = 0; k < 4; k++) {
        int nr = r + d[k];
        int nc = c + d[k+1];
        if (valid(nr, nc) && g[nr][nc] == 1) {
            total += dfs(nr, nc);
        }
    }
    return total;
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
    M = grid.size();
    N = grid[0].size();
    g = grid;

    int total_land = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (g[i][j] == 1) {
                total_land = max(total_land, dfs(i, j));
            }
        }
    }

    return total_land;
}

int main() {
    return 0;
}