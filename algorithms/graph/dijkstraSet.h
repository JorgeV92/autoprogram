#include <vector>
#include <set>

#ifndef DIJKSTRASET_H 
#define DIJKSTRASET_H 

const int inf = 1000000000;
std::vector<std::vector<std::pair<int,int>>> adj;

void dijkstra(int s, std::vector<int>& d, std::vector<int>& p) {
    int n = adj.size();
    d.assign(n, inf); p.assign(n,-1);
    d[s] = 0;
    std::set<std::pair<int,int>> q;
    q.insert({0,s});
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());
        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;
            if (d[v] + len < d[to]) {
                q.erase({d[to], to});
                d[to] = d[v] + len;
                p[to] = v;
                q.insert({d[to], to});
            }
        }
    }
}

std::vector<int> restore_path(int s, int t, std::vector<int> const& p) {
    std::vector<int> path;
    for (int v = t; v != s; v = p[v]) {
        path.push_back(v);
    }
    path.push_back(s);
    reverse(path.begin(), path.end());
    return path;
}

#endif