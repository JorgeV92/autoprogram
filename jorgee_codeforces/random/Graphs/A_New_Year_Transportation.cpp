#include <iostream>
#include <vector>

using namespace std; 

// DFS

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t;
    cin >> n >> t;

    vector<vector<int>> g(n+1);
    for (int i = 1; i < n; i++) {
        int a;
        cin >> a;
        g[i].push_back(i + a);
    }

    vector<int> vis(n+1,false);

    auto dfs = [&](auto&& dfs, int v) -> void {
        vis[v] = true;
        for (int u :g[v]) {
            if (!vis[u]) 
                dfs(dfs, u);
        }
    };

    dfs(dfs, 1);

    if (vis[t]) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}