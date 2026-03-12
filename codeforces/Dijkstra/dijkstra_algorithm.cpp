#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>

using namespace std;

#define pii pair<int,int>

const int INF  = 1e9 + 7;

int n, m;
vector<vector<pii>> g;
vector<int> dist, p;

vector<int> restore_path(int s, int t) {
    vector<int> path;
    for (int v = t; v != s; v = p[v]) {
        path.push_back(v);
    }
    path.push_back(s);
    reverse(path.begin(), path.end());
    return path;
}

void dijkstra(int s,  int t) {
    dist[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, s});
    
    while (!pq.empty()) {
        auto [d_v, v] = pq.top();
        pq.pop();
        if (d_v != dist[v]) continue;
        
        for (const auto& e : g[v]) {
            int to = e.first;
            int len = e.second;

            if (len + dist[v] < dist[to]) {
                dist[to] = dist[v] + len;
                p[to] = v;
                pq.push({dist[to], to});
            }
        }
    }
    
    if (dist[t] == INF) {
        cout << -1;
        return;
    } else {
        vector<int> path = restore_path(s, t);
        for (int v : path) {
            cout << v + 1 << " "; 
        }
        cout << endl;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    g = vector<vector<pii>>(n);
    dist.assign(n, INF);
    p.assign(n, -1);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    dijkstra(0, n-1);
    
    return 0;
}