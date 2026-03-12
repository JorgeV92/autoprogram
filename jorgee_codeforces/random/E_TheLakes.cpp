#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 2009;
vector<int> grid[MAXN];
int n, m;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

bool valid(int r, int c) {
    return (0 <= r && r < n && 0 <= c && c < m);
}

int dfs(int r, int c) { 
    int sum = grid[r][c];
    grid[r][c] = 0;
    for (int k = 0; k < 4; k++) {
        int nr = r + dx[k];
        int nc = c + dy[k];
        if (valid(nr,nc) && grid[nr][nc] != 0) {
            sum += dfs(nr, nc);
        }
    }
    return sum;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        grid[i].clear();
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            grid[i].push_back(x);
        }
    }

    int mx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] != 0) {
                mx = max(mx, dfs(i, j));
            }
        }
    }
    cout << mx << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}