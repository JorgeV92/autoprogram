#include <iostream>
#include <vector>

using namespace std;

int n, q, l;
int timer;
vector<int> tin, tout, depth;
vector<vector<int>> tree, up;

void dfs(int v, int p) {
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; i++) {
        up[v][i] = up[up[v][i-1]][i-1];
    }

    for (int u : tree[v]) {
        if (u == p) continue;
        depth[u] = depth[v] + 1;
        dfs(u, v);
    }
    tout[v] = ++timer;
}

bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >=  tout[v];
}

int lca(int u, int v) {
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u)) return v;
    for (int i = l; i >= 0; i--) {
        if (!is_ancestor(up[u][i], v)) {
            u = up[u][i];
        }
    }
    return up[u][0];
}

int distance(int a, int b) {
    return depth[a] + depth[b] - 2 * depth[lca(a, b)];
}

void preprocess(int root) {
    timer = 0;
    l = 1;
    while ((1 << l) <= n) l++;
    tin.resize(n+1);
    tout.resize(n+1);
    depth.resize(n+1, 0);
    up.assign(n+1, vector<int>(l+1));
    dfs(root, root);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    tree.resize(n+1, {});
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    preprocess(1);

    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << distance(a,b) << "\n";
    }

    return 0;
}