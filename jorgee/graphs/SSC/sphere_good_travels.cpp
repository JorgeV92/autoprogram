#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long
#define vi vector<int>

vector<bool> visited;
vector<ll> fun_values;
int N, M, S, E;

void dfs(int v, vector<vector<int>>& adj, vector<int>& out) {
     visited[v] = true;
     for (int u : adj[v]) {
        if (!visited[u]) {
            dfs(u, adj, out);
        }
     }
     out.push_back(v);
}

// Kosaraju's Algorithm
void strongly_connected_components(vector<vi>& adj,
                                    vector<vi>& components,
                                   vector<vi>& adj_cond) {
    int n = adj.size();
    components.clear(); adj_cond.clear();
    vector<int> order;
    visited.assign(n, false);

    for (int i = 0 ; i < n; i++) {
        if (!visited[i]) 
            dfs(i, adj, order);
    }

    vector<vector<int>> adj_rev(n);
    for (int v = 0; v < n; v++) {
        for (int u : adj[v]) {
            adj_rev[u].push_back(v);
        }
    }
    vector<ll> scc_fun(n, 0);
    visited.assign(n, false);
    reverse(order.begin(), order.end());

    vector<int> roots(n, 0);

    for (auto v : order) {
        if (!visited[v]) {
            vector<int> component;
            dfs(v, adj_rev, component);
            components.push_back(component);
            int root = *min_element(component.begin(), component.end());
            ll current_total_fun = 0;
            for (auto u : component) {
                roots[u] = root;
                current_total_fun += fun_values[u];
            }
            scc_fun[root] = current_total_fun;
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

    // DP on DAG
    vector<ll> dp(n, -1);
    int start_scc = roots[S];
    int end_scc = roots[E];

    dp[start_scc] = scc_fun[start_scc];

    for (int i = 0; i < components.size(); i++) {
        int v = *min_element(components[i].begin(), components[i].end());
        if (dp[v] == -1) continue;
        for (int u : adj_cond[v]) {
            if (dp[u] < dp[v] + scc_fun[u]) {
                dp[u] = dp[v] + scc_fun[u];
            }
        }
    }

    cout << dp[end_scc];

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> S >> E;
    S--; E--;
    fun_values.resize(N);
    for (int i = 0; i < N; i++) cin >> fun_values[i];

    vector<vector<int>> adj(N);
    for (int i = 0; i < M; i++) {
        int u, v; 
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
    }

    vector<vector<int>> components;
    vector<vector<int>> adj_cond;
    strongly_connected_components(adj, components, adj_cond);

    return 0;
}