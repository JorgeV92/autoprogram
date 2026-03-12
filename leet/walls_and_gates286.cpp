#include <iostream>
#include <vector>

using namespace std;

const int INF = 2e31 - 1;

void wallsAndGates(vector<vector<int>>& rooms) {
    int m = rooms.size();
    int n = rooms[0].size();

    queue<pair<int,int>> q;
    for (int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if (rooms[i][j] == 0) {
                q.push({i, j});
            }
        }
    }

    auto valid = [&](int x, int y) -> bool {
        return (0 <= x && x < m && 0 <= y && y < m);
    };

    int d[5] = {-1, 0, 1, 0, -1};
    while (!q.empty()) {
        auto [r, c] = q.front(); 
        q.pop();
        for (int k = 0; k < 4; k++) {
            int nr = r + d[k];
            int nc = c + d[k+1];
            if (valid(nr, nc) && rooms[nr][nc] == INF) {
                rooms[nr][nc] = rooms[r][c] + 1;
            }
        }
    }
    
}

int main() {
    return 0;
}