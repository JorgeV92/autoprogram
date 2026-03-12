#include <vector>
#include <queue>

#ifndef DIJKSTRAPQ_H
#define DIJKSTRAPQ_H

const int INF = 1000000000;
std::vector<std::vector<std::pair<int,int>>> adj;

void dijkstra(int s, std::vector<int>& d, std::vector<int>& p) {
    int n = adj.size();
    d.assign(n,INF); p.assign(n,-1);
    d[s] = 0;
    using pii = std::pair<int,int>;
    std::priority_queue<pii,std::vector<pii>, std::greater<pii>> pq;
    pq.push({0,s});
    while (!pq.empty()) {
        auto [d_v, v] = pq.top();
        pq.pop();
        if (d_v != v) continue;
        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                pq.push({d[to], to});
            }
        } 
    }
}

#endif