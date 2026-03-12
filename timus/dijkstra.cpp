#include <iostream>
#include <vector>
#include <queue>

using namespace std; 

using i64 = long long;
constexpr i64 INF = 1e18;

#define pli pair<i64, int>

vector<vector<pli>> adj;
vector<i64> dist;
vector<int> p;
int n, m;

vector<int> restore_path(int s, int t) {
    vector<int> path;
    for (int v = t; v != s; v = p[v]) {
        path.push_back(v);
    }
    path.push_back(s);
    reverse(path.begin(), path.end());
    return path;
}

void dijkstra(int s) {
    dist.assign(n, INF);
    p.assign(n,-1);
    priority_queue<pli, vector<pli>, greater<pli>> h;
    h.push({0, s});
    dist[s] = 0;
    while (!h.empty()) {
        auto [d_v, v] = h.top();
        h.pop();
        if (d_v != dist[v]) continue;

        for (auto& edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (dist[v] + len < dist[to]) {
                dist[to] = dist[v] + len;
                p[to] = len;
                h.push({dist[to], to});
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << dist[i] << " \n"[i+1==n];
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    adj = vector<vector<pli>>(n);
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        a--; b--;
        adj[a].push_back({b, w});
    }
    dijkstra(0);
    return 0;
}