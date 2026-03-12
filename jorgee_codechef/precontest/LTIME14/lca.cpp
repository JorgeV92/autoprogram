#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n, l, timer;
vector<int> tin, tout;
vector<vector<int>> tree, up;

void dfs(int v, int p) {
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; i++) {
        up[v][i] = up[up[v][i-1]][i-1];
    }
    for (int u : tree[v]) {
        if (u != p) {
            dfs(u, v);
        }
    }
    tout[v] = ++timer;
}

bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
    if (is_ancestor(u, v)) {
        return u;
    } 
    if (is_ancestor(v, u)) {
        return v;
    }
    for (int i = l; i >= 0; i--) {
        if (!is_ancestor(up[u][i], v)) {
            u = up[u][i];
        }
    }
    return up[u][0];
}

int main() {
    cin >> n;
    tree = vector<vector<int>>(n);
    tin = vector<int>(n);
    tout = vector<int>(n);
    timer = 0;
    l = ceil(log2(n));
    up = vector<vector<int>>(n, vector<int>(l+1));
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    
    dfs(0, 0);
    
    int q;
    cin >> q;
    while (q--){
        int x, y;
        cin >> x >> y;
        x--; y--;
        cout << lca(x, y)+1 << endl;
    }
}