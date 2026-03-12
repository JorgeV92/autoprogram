#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<bool> vis;
vector<vector<int>> g, g_reversed;
vector<int> cities;
int n, m;

void dfs(int v, vector<vector<int>>& adj) {
    vis[v] = true;
    for (int u : adj[v]) {
        if (!vis[u]) {
            dfs(u, adj);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    g = vector<vector<int>>(n, vector<int>(m));
    g_reversed = vector<vector<int>>(n, vector<int>(m));
    vis = vector<bool>(n, false);

    for (int i = 0; i < m; i++ ) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g_reversed[b].push_back(a);
    }


    dfs(0, g);
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            cout << "NO\n";
            cout << i + 1 << " " << 1 << endl;
            return 0;
        }
    }
    
   //  vis.clear();
    vis.assign(vis.size(), false);

    dfs(0, g_reversed);
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            cout << "NO\n";
            cout << i + 1 << " " << 1 << endl;
            return 0;
        }
    }

    cout << "YES" << endl;

    return 0;
}
