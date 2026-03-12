#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std; 

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

string dir = "DULR";
int p[1005][1005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    auto valid = [&](int x, int y) {
        return (0 <= x && x < n && 0 <= y && y < m);
    };
 
    vector<string> grid(n);
    for (int i = 0 ; i < n; i++) {
        cin >> grid[i];
    }
    using pii = pair<int,int>;
    queue<pii> q;
    int r, c;
    for (int i = 0 ; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'M')
                q.push({i, j});
            else if (grid[i][j] == 'A') {
                r = i; c = j;
            }
        }   
    }
    q.push({r, c});
    p[r][c] = -1;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        if (grid[x][y] == 'A' && (x == 0 || x == n-1 || y == 0 || y == m-1)) {
            cout << "YES" << endl;
            string path;
            int d = p[x][y];
            while (d != -1) {
                path += dir[d];
                x -= dx[d];
                y -= dy[d];
                d = p[x][y];
            }
            reverse(path.begin(), path.end());
            cout << path.size() << endl;
            cout << path << endl;
            return 0;
        }
        for (int k = 0; k < 4; k++) {
            int nr = x + dx[k];
            int nc = y + dy[k];

            if (!valid(nr,nc) || grid[nr][nc] != '.') continue;
            grid[nr][nc] = grid[x][y];
            if (grid[nr][nc] == 'A') 
                p[nr][nc] = k;
            q.push({nr, nc});
        }
    }

    cout << "NO" << endl;

    return 0;   
}