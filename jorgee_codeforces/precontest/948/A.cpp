#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> g;
int n, m;
int dir[5] = {-1, 0, 1, 0, -1};

bool valid(int r, int c) {
    return (0 <= r && r < n && 0 <= c &&c < m);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    g.resize(n);
    for (int i = 0 ; i < n; i++) 
        cin >> g[i];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 'S') {
                for (int k = 0; k < 4; k++) {
                    int nr = i + dir[k];
                    int nc = j + dir[k+1];

                    if (valid(nr, nc) && g[nr][nc] == 'W') {
                        cout << "No\n";
                        return 0;
                    }
                }
            }
        }
    }
    
    for (int i =0 ; i < n; i++) {
        for (int j= 0; j < m; j++) {
            if (g[i][j] == '.') {
                g[i][j] = 'D';
            }
        }
    }
    cout << "Yes\n";
    for (int i = 0; i < n; i++) {
        cout << g[i] << endl;
    }

    return 0;
}