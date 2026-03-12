#include <iostream>
#include <vector>
#include <queue>

using namespace std; 

#define pii pair<int,int>
constexpr int inf = 1e9;

vector<vector<pii>> adj;
vector<int> dist;
vector<bool> vis;

vector<int> shortestReach(int n, vector<vector<int>> edges, int s) {
    adj = vector<vector<pii>>(n+1);
    for (const auto& e : edges) {
        int u = e[0], v = e[1], w = e[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dist.assign(n+1, inf);
    priority_queue<pii, vector<pii>, greater<pii>> h;
    h.push({0, s});
    dist[s] = 0;
    while (!h.empty()) {
        auto [d_v, v] = h.top();
        h.pop();
        if (d_v != dist[v]) continue;
        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (dist[v] + len < dist[to]) {
                dist[to] = dist[v] + len;
                h.push({dist[to], to});
            }
        }
    }

    vector<int> out;
    for (int i = 1; i <= n; i++) {
        if (i == s) continue;
        if (dist[i] == inf) {
            out.push_back(-1);
        }  else {
            out.push_back(dist[i]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}