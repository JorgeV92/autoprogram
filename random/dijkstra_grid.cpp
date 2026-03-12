#include <iostream>
#include<vector>
#include <queue>

using namespace std;

const int INF = 1e9+ 7;

void shortestPathInGrid(vector<vector<int>>& grid, int x1, int y1, int x2, int y2) {
    int n = grid.size();
    int m = grid[0].size();
    int d[5] = {-1,0,1,0,-1};
    using state = pair<int,pair<int,int>>;
    vector<vector<bool>> vis(n ,vector<bool>(m));
    vector<vector<int>> dist(n, vector<int>(m, INF));
    priority_queue<state, vector<state>, greater<state>> pq;
    
    auto valid = [&](int r , int c) -> bool {
        return (0 <= r && r < n && 0 <= c && c < m);
    };

    dist[0][0] = grid[0][0];
    pq.push({dist[x1][y1], {x1, y1}});

    while (!pq.empty()) {  
        auto [cost, rc] = pq.top();
        pq.pop();
        int r = rc.first;
        int c = rc.second;
        if (vis[r][c]) continue;
        vis[r][c] = true;
        if (r == x2 && c == y2) {
            cout << cost << endl;
            return;
        }
        for (int k = 0; k < 4; k++) {
            int nr = r + d[k];
            int nc = c + d[k+1];
            if (!valid(nr, nc)) 
                continue;
            int newCost = cost + grid[nr][nc];
            if (newCost < dist[nr][nc]) {
                dist[nr][nc] = newCost;
                pq.push({newCost, {nr, nc}});
            }
        }
    } 

    cout << -1 << endl;
}

int main() {
    vector<vector<int>> grid = {
        {1, 3, 5, 9, 2},
        {2, 1, 3, 4, 3},
        {5, 6, 1, 2, 5},
        {3, 3, 2, 1, 4},
        {1, 5, 3, 9, 1}
    };

    const int n = grid.size();
    const int m = grid[0].size();

    shortestPathInGrid(grid, 0, 0, n-1, m-1);
} 