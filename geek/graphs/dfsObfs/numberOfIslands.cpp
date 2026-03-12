#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std; 

#define vi vector<int>

vector<vector<char>> g;
vector<vector<bool>> vis;
int n, m;
int dir[9] ={-1, 0, 1, 0, -1, 1, 1, -1, -1};
bool valid(int r, int c) {
    return (0 <= r && r < n && 0 <= c && c < m);
}

void dfs(int r, int c) {
    vis[r][c] = true;
    for (int k = 0; k < 8; k++) {
        int nr = r + dir[k];
        int nc = c + dir[k+1];
        if (valid(nr, nc) && !vis[nr][nc] && g[nr][nc] == 'L') {
            dfs(nr, nc);
        }
    }
}

int countIslands2(vector<vector<char>>& grid) {
    // Code here
    g = grid;
    n = g.size();
    m = g[0].size();
    vis = vector<vector<bool>>(g.size(), vector<bool>(g[0].size()));
    
    int total = 0;
    for (int i =0 ;i < g.size(); i++) {
        for (int j = 0; j < g[0].size(); j++) {
            if (!vis[i][j] && grid[i][j] == 'L') {
                dfs(i, j);
                total++;
            }
        }
    }
    return total;
}

struct DSU {
    vi e; void init(int N) { e = vi(N, -1); }
    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
    bool sameSet(int x, int y) { return get(x) == get(y); }
    int size(int x) { return -e[get(x)]; }
    bool unite(int x, int y) {
        x = get(x); y = get(y);
        if (x == y) return false;
        if (e[x] > e[y]) swap(x,  y);
        e[x] += e[y];
        e[y] = x;
        return true;
    }
};  

int countIslands(vector<vector<char>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    DSU D;
    D.init(m * n);

    auto idx = [&](int r, int c) {
        return r * n + c;
    };

    auto valid = [&](int r, int c) {
        return (0 <= r && r < m && 0 <= c && c < n);
    };

    int dir[9] = {-1, 0, 1, 0, -1, 1, 1, -1, -1};

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 'L') {
                for (int k =0; k < 9; k++) {
                    int nr = i + dir[k];
                    int nc = j + dir[k+1];
                    if (valid(nr, nc) && grid[nr][nc] == 'L') {
                        D.unite(idx(i, j), idx(nr, nc));
                    }
                }
            }
        }
    }

    unordered_set<int> se;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 'L') {
                se.insert(D.get(idx(i, j)));
            }
        }
    }
    return se.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}