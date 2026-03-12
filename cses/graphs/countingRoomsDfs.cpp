#include <iostream>
#include <vector>
#include <string>

using namespace std; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    auto valid = [&](int r, int c) {
        return (0 <= r && r < n && 0 <= c && c < m);
    };

    int d[] = {-1, 0, 1, 0, -1};

    auto dfs = [&](auto&& dfs, int r, int c) -> void {
        grid[r][c] = '#';
        for (int k = 0; k < 4; k++) {
            int nr = r + d[k];
            int nc = c + d[k+1];
            if (valid(nr, nc) && grid[nr][nc] != '#') {
                dfs(dfs, nr, nc);
            }
        }
    };

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') {
                dfs(dfs, i, j);
                ans++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}