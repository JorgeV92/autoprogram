#include <iostream>
#include <vector>

using namespace std;

vector<string> grid;
int dx[] = {-1,0, 1, 0, 1, -1, -1, 1};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
int n;

bool valid(int r, int c) {
    return (0 <= r && r < 2 && 0 <= c && c < n);
}


bool dfs(int r, int c) {
    if (!valid(r, c)) return false;
    if (r == 1 && c == n-1) {
        return true;
    }
    grid[r][c] = '1';
    for (int k =0; k < 8; k++) {
        int nr = r + dx[k];
        int nc = c + dy[k];

        if (valid(nr, nc) && grid[nr][nc] != '1') {
            if (dfs(nr, nc)) return true;
        }
    }
    return false;
}

void solve() {
    if (dfs(0, 0)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    
    while (t--) {
        cin >> n;
        grid = vector<string>(2);
        for (int i = 0; i < 2; i++) {
            cin >> grid[i];
        }

        solve();
    }

    return 0;
}