#include <iostream>
#include <vector>
#include <queue>

using namespace std; 

int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
    if (A[0][0] == 0) return -1;

    auto valid = [&](int x, int y) {
        return (0 <= x && x < N && 0 <= y && y < M);
    };

    using pii = pair<int,int>;
    queue<pii> q;
    q.push({0,0});
    A[0][0] = 0;
    int t = 0;
    int dir[5] = {-1, 0, 1, 0, -1};

    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            auto [r, c] = q.front();
            q.pop();
            if (r == X && c == Y) {
                return t;
            }
            
            for (int k = 0; k < 4; k++) {
                int nr = r + dir[k];
                int nc = c + dir[k+1];

                if (valid(nr, nc) && A[nr][nc] == 1) {
                    q.push({nr, nc});
                    A[nr][nc] = 0;
                }
            }
        }
        t++;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}   