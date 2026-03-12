#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isBipartite(int V, vector<vector<int>> &edges) {
    vector<vector<int>> adj(V);
    for (const auto& e : edges) {
        int u = e[0];
        int v = e[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool is_bipartite = true;
    queue<int> q;
    vector<int> side(V, -1);
    for (int st = 0; st < V; st++) {
        if (side[st] == -1) {
            side[st] = 0;
            q.push(st);
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                for (int u : adj[v]) {
                    if (side[u] == -1) {
                        side[u] = side[v] ^ 1;
                        q.push(u);
                    } else {
                        is_bipartite &= side[u] != side[v];
                    }
                }
            }
        }
    }
    return is_bipartite;   
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}