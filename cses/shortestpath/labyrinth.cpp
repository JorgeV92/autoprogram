/**
 * Problem: Labyrinth
 * Algorithm: BFS (Breadth-First Search)
 * Time Complexity: O(N x M)
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define pii pair<int,int>
#define F first 
#define S second 

// 1000x1000 grid
const int MAXN = 1005;

int n, m;
char grid[MAXN][MAXN];
bool visited[MAXN][MAXN];
int parentMove[MAXN][MAXN]; // store the index of direction used to reach this cell

// Directions : Up, Right, Down, Left
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
string dirChars = "URDL";

int main() {
    // CP Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    pii start, end;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') start = {i, j};
            if (grid[i][j] == 'B') end = {i, j};
        }
    }

    queue<pii> q;
    q.push(start);
    visited[start.F][start.S] = true;

    auto valid = [&](int r, int c) -> bool {
        return (0 <= r && r < n && 0 <= c && c < m);
    };

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();

        if (curr == end) break;

        for (int k = 0; k < 4; k++) {
            int nx = curr.F + dx[k];
            int ny = curr.S + dy[k];

            if (valid(nx, ny) && grid[nx][ny] != '#' && !visited[nx][ny]) {
                visited[nx][ny] = true;
                parentMove[nx][ny] = k;
                q.push({nx, ny});
            }
        }
    }

    if (visited[end.F][end.S]) {
        cout << "YES" << endl;

        string path = "";
        pii curr = end;

        while (curr != start) {
            int p = parentMove[curr.F][curr.S];
            path += dirChars[p];

            // Move current back to previous cell
            // Note: if we moved direction dx[p] to get here, 
            // we subtract dx[p] to go back.
            curr.F -= dx[p];
            curr.S -= dy[p];
        }

        reverse(path.begin(), path.end());
        cout << path.length() << endl;
        cout << path << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}