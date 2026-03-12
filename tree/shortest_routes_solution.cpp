#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define T pair<long long, int>

const long long LLINF = 9e18;
vector<vector<pair<int,int>>> adj;
vector<long long> dist;


void dijkstra(int s) {
    int n = adj.size();
    dist.resize(n, LLINF);
    priority_queue<T, vector<T>, greater<T>> pq;
    dist[s] = 0;
    pq.push({0, s});
    
    while (!pq.empty()) {
        const auto [cdist, node] = pq.top();
        pq.pop();
        if (cdist != dist[node]) continue;
        for (auto edge : adj[node]) {
            int to = edge.first;        
            int len = edge.second;
            if (cdist + len < dist[to]) {
                dist[to] = cdist + len;
                pq.push(make_pair(dist[to], to));
            }
        }
    }
}




int main() {
    
    int n, m;
    scanf("%d%d", &n, &m);
    
    adj.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        a--; b--;
        adj[a].push_back(make_pair(b, c));
    }

    dijkstra(0);
    
    for (int v = 0; v < n; v++) {
        cout << dist[v] << " ";    
    }
    cout << endl;


    return 0;
}
