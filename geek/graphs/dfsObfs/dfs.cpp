#include <iostream>
#include <vector>

using namespace std; 

vector<vector<int>> adj;
vector<bool> vis;
vector<int> res;

void dfs(int u) {
    vis[u] = true;
    res.push_back(u);
    for (int v : adj[u]) {
        if (!vis[v]) 
            dfs(v);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    adj = {
        {1, 2},
        {0, 2},
        {0, 1, 3, 4},
        {2},
        {2}
    };
    int V = adj.size();
    vis.assign(V, false);
    dfs(0);

    for (int x : res) {
        cout << x << " ";
    }
    cout << endl;

    for (int i = 0; i < V; i++) {
        if (!vis[i]) 
            dfs(i);
    }

    return 0;
}

