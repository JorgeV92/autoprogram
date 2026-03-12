#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std; 

const int N = 200005;
vector<int> adj[N];
bool vis[N];
int parent[N];
int cycle_start, cycle_end;

bool dfs(int v, int p) {
    vis[v] = true;
    for (int u : adj[v]) {
        if (u == p) continue;
        if (vis[u]) {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
        parent[u] = v;
        if (dfs(u, v)) {
            return true;
        }
    }   
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;

    for (int i =0 ;i <= n; i++) {
        adj[i].clear();
    }

    memset(vis, false, sizeof(vis));
    memset(parent, -1, sizeof(parent));

    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cycle_start = cycle_end = -1;
    for (int v = 1; v <= n; v++) {
        if (!vis[v] && dfs(v, -1)) {
            break;
        }
    }

    if (cycle_start == -1) {
        cout << "IMPOSSIBLE\n";
    } else {
        vector<int> cycle{cycle_start};
        for (int v = cycle_end; v != cycle_start; v = parent[v]) {
            cycle.push_back(v);
        }
        cycle.push_back(cycle_start);
        reverse(cycle.begin(), cycle.end());
        cout << cycle.size() << endl;
        for (int i =0 ; i < cycle.size(); i++) {
            cout << cycle[i] << " \n"[i+1==cycle.size()];
        }
    }

    return 0;
}