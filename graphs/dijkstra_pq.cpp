#include <iostream>
#include <vector>
#include <queue>


using namespace std;


// Dijkstra's algorithm with priority queue

const int INF = 1000000000;
vector<vector<pair<int,int>>> adj;

void dijkstra_pq(int s, vector<int>& d, vector<int>& p) {
    const int n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);
    
    d[s] = 0;
    using pii = pair<int,int>;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, s}); // (0, s)
    
    while (!q.empty()) {
        int v = pq.top().second;
        int d_v = pq.top().first;
        pq.pop();
        if (d_v != dist[v]) continue;
    
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
    
}


int main() {
    
    return 0;
}
