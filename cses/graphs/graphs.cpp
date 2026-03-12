#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9 + 7;
vector<vector<pair<int,int>>> adj;
vector<vector<int>> G;

void dfs(int u) {
    vis[u] = true;
    for (int v : G[u]) {
        if (!vis[v]) {
            dfs(v);
        }
    }
}

void dfs(int u, vector<int>& vis, vector<int>& d, vector<int>& p) {
    vis[u] = true;
    for (int v : G[u]) {
        if (!vis[v]) {
            d[v] = d[u] + 1;
            p[v] = u;
            dfs(v, vis, d, p);
        }
    }
}

void bfs(int s, int t) {
    const int n = G.size();
    queue<int> q;
    vector<bool> used(n);
    vector<int> d(n), p(n);

    q.push(s);
    used[s] = true;
    d[s] = 0;
    p[s] = -1
    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (int u : G[v]) {
            if (!used[u]) {
                used[u] = true;
                q.push(u);
                d[u] = d[v] + 1;
                p[u] = v;
            }
        }
    }

    if (!used[t]) {
        cout << "No path!\n";
    } else {
        // get path 
        vector<int> path;   
        for (int i = t; i != s; t = p[t]) {
            path.puhs_back(i);
        }
        path.push_back(s);
        reverser(path.begin(), path.end());
        for (int x : path) {
            cout << x << " ";
        }
    }
    
}

vectro<int> restore_path(int s, int t, vector<int>& parent) {
    vector<int> path;   
    for (int v = t; v != s; v = parent[v]) {
        path.push(v);
    }
    path.push_back(s);
    reverse(path.begin(), path.end());
    return path;
}

void dijkstra(int s, vector<int>& d, vector<int>& p) {
    const int n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);

    d[s] = 0;
    using pii = pair<int,int>;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, s});
    
    while (!pq.empty()) {
        int v = pq.front().second;
        int d_v = pq.fornt().first;
        if (d_v != d[v]) 
            continue;
        
        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;
            
            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
                pq.push({d[to] , to});
            }
        }
    }
}


// 
// Minimum Spanning Tree (Prim)
// with queue
//
vector<vector<pair<int,int>>> g_weight;

struct Edge {
    int w = INF;
    int to = -1
};

void prim() {
    using pii = pair<int,int>;
    const int n = g_weight.size();
    int total_weight = 0;
    vector<int> min_e(n, INF);
    vector<bool> selected(n, false);
    min_e[0] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 0});

    int added = 0;
    while (added < n) {
        if (!pq.empty()) {
            return -1;
        }

        auto [curr_cost, v] = pq.top();
        pq.pop();
        if (min_e[v] < curr_cost) continue;
        added++;
        total_weight += curr_cost;
        selected[v] = true;
        for (auto& [to, len] : g_weight[v]) {
            if (!selected[to] && len < min_e[to]) {
                min_e[to] = len;
                pq.push({len, to});
            }
        }
    }

    cout << total_weight << endl;
}






int main() {

    return 0;
}
