// SSC strongly connected components of G 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> visited;

void dfs(int v, vector<vector<int>> const& adj, vector<int>& out) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u]) 
            dfs(u, adj, out);
    }
    out.push_back(v);
}

void strongly_connected_components(vector<vector<int>>const& adj,
                                   vector<vector<int>>& components,   
                                   vector<vector<int>>& adj_cond) {

    int n = adj.size();
    components.clear(); adj_cond.clear();
    vector<int> order;
    visited.assign(n, false);

    for (int i = 0; i < n; i++) {
        if (!visited[i])
            dfs(i, adj, order);
    }

    vector<vector<int>> adj_rev(n);
    for (int v = 0; v < n; v++) {
        for (int u : adj[v]) {
            adj_rev[u].push_back(v);
        }
    }

    visited.assign(n , false);
    reverse(order.begin(), order.end());

    vector<int> roots(n, 0); // the root vertex of a vertex's SSC

    for (auto v : order) {
        if (!visited[v]) {
            vector<int> component;
            dfs(v, adj_rev, component);
            components.push_back(component);
            int root = *min_element(component.begin(), component.end());
            for (auto u : component) {
                roots[u] = root;
            }
        }
    }

    adj_cond.assign(n, {});
    for (int v = 0; v < n; v++) {
        for (auto u : adj[v]) {
            if (roots[v] != roots[u]) {
                adj_cond[roots[v]].push_back(roots[u]);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 5;
    vector<vector<int>> adj(n);

    // SCC 1: 0 -> 1 -> 2 -> 0
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(0);

    // Bridge: 1 -> 3 (Connects SCC 1 to SCC 2)
    adj[1].push_back(3);

    // SCC 2: 3 -> 4 -> 3
    adj[3].push_back(4);
    adj[4].push_back(3);

    vector<vector<int>> components;
    vector<vector<int>> adj_cond;

    strongly_connected_components(adj, components, adj_cond);

    cout << "1. Found " << components.size() << " Strongly Connected Components:\n";
    for(size_t i = 0; i < components.size(); ++i) {
        // Calculate the root for display purposes (same logic as inside the function)
        int root = *min_element(components[i].begin(), components[i].end());
        
        cout << "   - Component Rooted at " << root << ": { ";
        for(int node : components[i]) {
            cout << node << " ";
        }
        cout << "}\n";
    }

    cout << "\n2. Condensation Graph (Adjacency List of Roots):\n";
    cout << "(Format: Root_Node -> [Neighbor_Roots])\n";
    
    // Check all possible roots
    bool found_edge = false;
    for(int i = 0; i < n; ++i) {
        if(!adj_cond[i].empty()) {
            found_edge = true;
            cout << "   Root " << i << " -> ";
            for(int neighbor : adj_cond[i]) {
                cout << neighbor << " ";
            }
            cout << "\n";
        }
    }
    
    if (!found_edge) cout << "   No edges between components.\n";

    return 0;   
}