#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

constexpr int MAXN = 200001;
constexpr int LOG = 18;

struct LCA {
    int N; vector<vector<int>> up, e; 
    vector<int> ea, eb, depth, val;
    void init(int _N) {
        N = _N;
        int d = 1;
        while ((1 << d) <= N) d++;
        up.assign(d, vector<int>(N));
        e.resize(N, {});
        ea.resize(N);
        eb.resize(N);
        val.assign(N, 0);
        depth.assign(N, 0);
    }

    void add_edge(int x, int y, int i) {
        e[x].push_back(y);
        e[y].push_back(x);
        ea[i] = x;
        eb[i] =  y;
    }

    void gen(int R = 0) {
        up[0][R] = R;
        dfs(R);
    }

    void dfs(int x = 0) {
        for (int i = 1; i < up.size(); i++) {
            up[i][x] = up[i-1][up[i-1][x]];
        }
        for (int y : e[x]) {
            if (y != up[0][x]) {
                up[0][y] = x;
                depth[y] = depth[x] + 1;
                dfs(y);
            }
        }
    }

    int jmp(int x, int d) {
        for (int i = up.size()-1; i >= 0; i--) {
            if ((d >> i) & 1) {
                x = up[i][x];
            }
        }
        return x;
    }

    int lca(int x, int y) {
        if (depth[x] < depth[y])
            swap(x, y);
        int k = depth[x] - depth[y];
        x = jmp(x, k);
        if (x == y) return x;
        for (int i = up.size() -1 ; i >= 0; i--) {
            int X = up[i][x], Y = up[i][y];
            if (X != Y) {
                x = X, y = Y;
            }
        }
        return up[0][x];
    }

    int la(int v, int f) {
        for (int u : e[v]) {
            if (u != f) 
                val[v] += la(u, v);
        }
        return val[v];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    LCA tree;
    tree.init(n);

    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        tree.add_edge(a, b, i);
    }

    tree.gen();

    int k;
    cin >> k;
    while (k--) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        int c = tree.lca(u, v);
        tree.val[u]++;
        tree.val[v]++;
        tree.val[c] -= 2;
    }
    tree.la(0, -1);

    for (int i= 0; i < n-1; i++) {
        if (tree.depth[tree.ea[i]] >  tree.depth[tree.eb[i]])
            swap(tree.ea[i], tree.eb[i]);
    }

    for (int i = 0; i < n-1; i++) {
        cout << tree.val[tree.eb[i]] << " \n"[i+1==n-1];
    }

    return 0;   
}