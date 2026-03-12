#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    int maximumMinutes(vector<vector<int>>& grid) {
        using pii = pair<int,int>;
        int m = grid.size(), n = grid[0].size();
        bool vis[m][n];
        bool fire[m][n];
        int dir[5] = {-1, 0, 1, 0, -1};

        auto spread = [&](queue<pii>& q) -> queue<pii> {
            queue<pii> nq;
            while (!q.empty()) {
                auto [i, j] = q.front();
                q.pop();
                for (int k = 0; k < 4; k++) {
                    int x = i + dir[k], y = j + dir[k+1];
                    if (x >=0 && x < m && y >= 0 && y < n && 
                        !fire[x][y] && grid[x][y] == 0) {
                        fire[x][y] = true;
                        nq.emplace(x, y);
                    }
                }
            }
            return nq;
        };

        auto check = [&](int t) -> bool {
            memset(vis, false, sizeof(vis));  
            memset(fire, false, sizeof(fire));
            queue<pii> q1;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == 1) {
                        q1.emplace(i, j);
                        fire[i][j] = true;
                    }
                }
            }
            
            for (; t && q1.size(); --t) {
                q1 = spread(q1);
            }
            if (fire[0][0]) 
                return false;

            queue<pii> q2;
            q2.emplace(0, 0);
            vis[0][0] = true;
            for (; q2.size(); q1 = spread(q1)) {
                int len = q2.size();
                for (int d = 0; d < len; d++) {
                    auto [i, j] = q2.front();
                    q2.pop();
                    if (fire[i][j]) 
                        continue;
                    for (int k = 0; k < 4; k++) {
                        int x = i + dir[k], y = j + dir[k+1];
                        if (x >= 0 && x < m && y >= 0 && y < n && 
                            !vis[x][y] && !fire[x][y] && grid[x][y] == 0) {
                                if (x == m -1 && y == n-1) 
                                    return true;
                                vis[x][y] = true;
                                q2.emplace(x, y);
                        }
                    }
                }
            }
            return false;
        };

        int l = -1, r = m*n;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (check(mid)) {
                l = mid;
            } else {
                r = mid-1;
            }
        }
        return l == n*m ? 1e9 : l;
    } 
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    return 0;
}

