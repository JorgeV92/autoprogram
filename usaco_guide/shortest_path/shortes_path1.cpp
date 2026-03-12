#include <iostream>
#include <vector>
#include <queue>

using namespace std;

using i64 = long long;
#define pli pair<i64, int>

constexpr i64 inf = 1e18;

int n, m;
vector<vector<pair<int, int>>> adj;

void dijkstra(int s) {
    vector<i64> d(n, inf);
    priority_queue<pli, vector<pli>, greater<pli>> h;
    h.push({0, s});
    d[s] = 0;
    while (!h.empty()) {
        auto [d_v, v] = h.top();
        h.pop();
        if (d_v != d[v]) continue;

        for (auto& edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                h.push({d[to], to}); 
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << d[i] << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    adj = vector<vector<pair<int, int>>>(n);
    for (int i = 0; i < m; i++) {
        int u, v , w;
        cin >> u >> v >> w;
        u--; v--;
        adj[u].push_back({v, w});
    }

    dijkstra(0);

    return 0;
}
