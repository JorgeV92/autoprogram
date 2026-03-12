#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int n, m;
int dir[5] = {-1, 0, 1, 0, -1};
vector<vector<int>> g;

bool valid(int r, int c) {
    return (0 <= r && r < n && 0 <= c && c < m);
}

void dijkstra(int x, int y, int ex, int ey) {
    using state = pair<int, pair<int,int>>;
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

    priority_queue<state, vector<state>, greater<state>> pq;
    pq.push({g[x][y], {x, y}});
    dist[x][y] = g[x][y];

    while (!pq.empty()) {
        auto [cost, rc] = pq.top();
        int r  = rc.first;
        int c = rc.second;
        if (cost != dist[r][c]) continue;
        pq.pop();
        if (r == ex && c == ey)  {
            cout << cost << endl;
            return;
        };

        for (int k = 0; k < 4; k++) {
            int nr = r + dir[k];
            int nc = c + dir[k+1];
            
            if (valid(nr, nc)) {
                if (cost + g[nr][nc] < dist[nr][nc]) {
                    dist[nr][nc] = cost + g[nr][nc];
                    pq.push({dist[nr][nc], {nr, nc}});
                }
            }
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> grid = {
        {1, 3, 5, 9, 2},
        {2, 1, 3, 4, 3},
        {5, 6, 1, 2, 5},
        {3, 3, 2, 1, 4},
        {1, 5, 3, 9, 1}
    };

    g = grid;
    n = g.size();
    m = grid[0].size();

    dijkstra(0,0,n-1,m-1);

    return 0;
}