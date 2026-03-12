#include <iostream>
#include <vector>
#include <deque>
#include <string>

using namespace std;

using pii = pair<int,int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    int dir[5] = {-1, 0, 1, 0, -1};
    vector<vector<int>> depth(n, vector<int>(m, -1));    
    deque<pii> dq;
    dq.push_front({0,0});
    depth[0][0] = 1;

    auto valid = [&](int r, int c) -> bool {
        return (0 <= r && r < n && 0 <= c && c < m);
    };

    int ans = 1;
    while (!dq.empty()) {
        auto [r, c] = dq.front();
        dq.pop_front();
        ans = max(ans, depth[r][c]);

        for (int k = 0; k < 4; k++) {
            int nr = r + dir[k];
            int nc = c + dir[k+1];

            if (valid(nr, nc) && depth[nr][nc] == -1 && grid[nr][nc] != '.') {
                if (grid[r][c] == grid[nr][nc]) {
                    depth[nr][nc] = depth[r][c];
                    dq.push_front({nr, nc});
                } else {
                    depth[nr][nc] = depth[r][c] + 1;
                    dq.push_back({nr, nc});
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}