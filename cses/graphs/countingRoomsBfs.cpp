#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    using pii = pair<int,int>;
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n ; i++) {
        cin >> grid[i];
    }

    auto valid = [&](int r, int c) {
        return (0 <= r && r < n && 0 <= c && c < m);
    };

    int d[] = {-1, 0, 1, 0, -1};

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') {
                queue<pii> q;
                q.push({i, j});
                grid[i][j] = '#';
                ans++;
                while (!q.empty()) {
                    auto [r, c ] = q.front();
                    q.pop();
                    
                    for (int k = 0; k < 4; k++) {
                        int nr = r + d[k];
                        int nc = c + d[k+1];

                        if (valid(nr,nc) && grid[nr][nc] != '#') {
                            q.push({nr, nc});
                            grid[nr][nc] = '#';
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}