#include <iostream>
#include <vector>

using namespace std; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n;

    vector<vector<char>> b(n, vector<char>(n, '.'));
    int ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;
    ax--; ay--; bx--; by--; cx--; cy--;

    b[ax][ay] = 'Q';
    b[bx][by] = 'K';
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == ax || j == ay || abs(i - ax) == abs(j - ay)) {
                b[i][j] = 'N';
            }
        }
    }

    auto valid = [&](int r, int c) {
        return (0 <= r && r < n && 0 <= c && c < n);
    };

    int dx[] = {1, 0, -1, 0, 1, -1, 1, -1};
    int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

    auto dfs = [&](auto&&dfs, int r, int c) {
        if (r == cx && c == cy) {
            return true;
        }
        b[r][c] = '#';
        for (int k = 0; k < 8; k++) {
            int nr = r + dx[k];
            int nc = c + dy[k];

            if (!valid(nr, nc) || b[nr][nc] == 'N' || b[nr][nc] == '#')
                continue;
            if (dfs(dfs, nr, nc)) {
                return true;
            }
        }
        return false;
    };

    if (dfs(dfs, bx, by)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    /*
        Given soluion O(1) time.

        int ax, ay, bx, by, cx, cy;
        cin >> ax >> ay >> bx >> by >> cx >> cy;

        bool x = (bx < ax) == (cx < ax);
        bool y = (by < ay) == (cy < ay);

        if (x && y ) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    */

    return 0;
}