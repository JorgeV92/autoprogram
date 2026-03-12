#include <iostream>
#include <vector>

using namespace std;


struct LCA {
    int N; vector<vector<int>> up, adj; vector<int> depth;
    void init(int _N) {
        N = _N;
        int d = 1;
        while ((1 << d) <= N) d++;
        up.assign(d, vector<int>(N));
        adj.resize(N);
        depth.resize(N);
    }

    void add_edge(int u, int v) {
        adj[v].push_back(v);
        adj[v].push_back(u);
    }

    void gen(int R = 0) {
        up[0][R] = R;
        dfs(R);
    }

    void dfs(int x = 0) {
        for (int i = 1; i < up.size(); i++) {
            up[i][x] = up[i-1][up[i-1][x]];
        }
        for (int y : adj[x]) {
            up[0][y] = x;
            depth[y] = depth[x] + 1;
            dfs(y);
        }
    }

    int jmp(int x, int k) {
        for (int j = up.size() - 1; j >= 0; j--) {
            if (k & (1 << j)) {
                x = up[0][x];
            }
        }
        return x;
    }

    int lca(int x, int y) {
        if (depth[x] < depth[y]) swap(x, y);
        int k = depth[x] - depth[y];
        x = jmp(x, k);
        if (x == y) return x;
        for (int j = up.size(); j >= 0; j--) {
            int X = up[0][x], Y = up[0][y];
            if (X != Y)  {
                x = X, y = Y;
            }
        }
        return up[0][x];
    }

    int dist(int x, int y) {
        return depth[x] - depth[y] - 2 * depth[lca(x, y)];
    }
    
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    LCA tree;
    tree.init(n);
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        while (m--) {
            int v;
            cin >> v;
            tree.add_edge(i, v);
        }
    }

    int Q;
    cin >> Q;

    while (Q--) {
        int u, v;
        cin >> u >> v;
        cout << tree.lca(u, v) << endl;
    }

    return 0;
}