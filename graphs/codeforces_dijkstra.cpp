#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1000000000;

vector<vector<pair<int,int>>> adj;

vector<int> restore_path(int s, int t, vector<int>& p) {
    vector<int> path;
    for (int v = t; v != s; v = p[v]) {
        path.push_back(v);
    } 
    path.push_back(s);
    reverse(path.begin(), path.end());
    return path;
}

void dijkstra(int s, int t, vector<int>& d)  {
    using pii = pair<int,int>;
    const int n = adj.size();
    d[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, s}); 
    vector<int> p(n+1, -1);

    while (!pq.empty()) {
        int v = pq.top().second;
        int d_v = pq.top().first;
        pq.pop();
        
        if (d_v != d[v]) continue;
        
        for (auto& edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;
            
            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
                pq.push({d[to], to});
            }
        }
    }
    vector<int> path = restore_path(s, t, p);
    
    for (int v : path) {
        cout << v << " ";
    }
    cout << endl;
}


int main() {
    int n, m;
    cin >> n >> m;
        
    adj.assign(n+1, {});
    
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> dist(n+1, INF);
    dijkstra(1, n, dist);
    
    return 0;
} 


