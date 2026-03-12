#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    const int n = grid.size();
    const int m = grid[0].size();

    // 0 empty
    // 1 freash
    // 2 rotten 

    // from each rotten cell we can insert into a queue
    // and starting from these locations (x, y), we look 
    // at the neighboring cells for fresh oranges and 
    // add 1 plus the current location time to reach 
    // and make these rotten as well.
    // To test whether we made all oranges rotten 
    // we can count how many freah oranges we 
    // have then in the end check if we visited
    // every fresh orange.  


    vector<pair<int,int>> dir{{1,0}, {-1,0}, {0,1}, {0,-1}, {1,1}};
    int fresh = 0;
    queue<pair<int,int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '2') {
                q.push({i, j});
            } else if (grid[i][j] == 1) {
                fresh++;
            }
        }
    }
    int time = 0;
    while (!q.empty()) {
        time++;
        int l = q.size();
        for (int i = 0; i < l; i++) {
            auto [u, v] = q.front(); q.pop();
            for (const auto& [du, dv] : dir) {
                int nu = u + du, nv = v + dv;
                if (nu < 0 || nu >= n || nv <0 || nv >= m || grid[nu][nv] != 1) 
                    continue;
                grid[nu][nj] = 2;
                fresh--;
                q.push({nu, nv});     
            }
        }
    }

    return fresh == 0 ? mintues-1 : -1;
    
}

int main() {

    
}
