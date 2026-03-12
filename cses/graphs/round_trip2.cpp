#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// For directed graphs

vector<vector<int>> adj;
vector<char> color; // (0, not visited), (1, visiting), (2, done visiting)
vector<int> parent; 
int cycle_start, cycle_end;

bool dfs(int v) {
    color[v] = 1;
    for (int u : adj[v]) {
        if (color[u] == 0) {
            parent[u] = v;
            if (dfs(u)) 
                return true;    
        } else if (color[u] == 1) {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
    }

    color[v] = 2;
    return false;
}

int main() {

    int n, m;
    cin >> n >> m;
    
    adj.assign(n+1, {});
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    color.assign(n+1, 0);
    parent.assign(n+1, -1);
    cycle_start =  -1;

    for (int v = 1; v <= n; v++) {
        if (color[v] == 0 && dfs(v)) {
            break;
        }
    }

    if (cycle_start == -1) { 
        cout << "IMPOSSIBLE\n";
        return 0;
    } else {
        vector<int> cycle;
        cycle.push_back(cycle_start);
        for (int v = cycle_end; v != cycle_start; v = parent[v]) {
            cycle.push_back(v);
        }
        cycle.push_back(cycle_start);
        reverse(cycle.begin(), cycle.end());
        
        cout << cycle.size() << endl;    
        for (int w : cycle) {
            cout << w << " ";
        }
        cout << endl;
    }

    return 0;
}
