#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

const int INF = 1e9 + 7;

int distance(int x, int x_, int y, int y_) {
    return abs(x - x_) + abs(y - y_);
}

// Minimum Spanning Tree using Prims algorithm with priority queue
int minCostConnectPointsPrimQueue(vector<vector<int>>& points) {
    const int n = points.size();
    vector<vector<pair<int,int>>> adj(n);
    
    // build a graph with a connection to all other points for each point
    for (int i = 0; i < n; i++) {
        int x = points[i][0];
        int y = points[i][1];
        for (int j = i+1; j < n; j++) {
            int x_prime = points[j][0];
            int y_prime = points[j][1];

            int dist = distance(x, x_prime, y, y_prime);
            adj[i].push_back({j, dist});
            adj[j].push_back({i, dist});
        } 
    }

    // MST 
    int total_weight = 0;
    vector<int> visited(n);
    vector<int> min_e(n, INF);
    min_e[0] = 0;
    using pii = pair<int,int>;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 0});
 
    int added = 0;
    while (added < n) {
        if (pq.empty()) return -1;
        auto [curr_cost, v] = pq.top();
        pq.pop();
        if (min_e[v] < curr_cost) continue;
        added++;
        total_weight += curr_cost;
        visited[v] = true;
        for (auto& edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;
            if (!visited[to] && len < min_e[to]) {
                min_e[to] = len;
                pq.push({len ,to});
            }
        } 
    }

    return total_weight;
}

// Minimum Spanning Tree using Prims algorithm with matrix and array
int minCostConnectPointsPrimArray(vector<vector<int>>& points)  {
    // Using a Matrix
    const int n = points.size();
    vector<vector<int>> adj(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        int x1 = points[i][0];
        int y1 = points[i][1];
        for (int j = i+1; j < n; j++) {
            int x2 = points[j][0];
            int y2 = points[j][1];
            int d = abs(x1-x2) + abs(y1-y2);
            adj[i][j] = d;
            adj[j][i] = d;
        }
    }

    // MST 
    vector<int> dist(n, INT_MAX);
    vector<bool> vis(n, false);
    dist[0] = 0;
    int total_weight = 0;
    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++) {
            if (!vis[j]  && (v == -1 || dist[j] < dist[v])) {
                v = j;
            }
        }
            
        vis[v] = true;
        total_weight += dist[v];
        for (int to = 0; to < n; to++) {
            if (adj[v][to] < dist[to]) {
                dist[to] = adj[v][to];
            }
        }
    }
    return total_weight;
}


// Minimum Spanning Tree using Kruskal algoritm with DSU
struct DSU {
    vector<int> e; void init(int N ) { e = vector<int>(N, -1); }
    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
    bool sameSet(int x, int y) { return get(x) == get(y); }
    bool unite(int x, int y) {
        x = get(x); y = get(y);
        if (x == y) return false;
        if (e[x] > e[y]) swap(x, y);
        e[x] += e[y];
        e[y] = x;
        return true;
    }
};

struct edge {
    int from;
    int to;
    int cost;
};

void minCostConnectPointsKruskal(vector<vector<int>>& points) {
    int n = points.size();
    vector<edge> edges;
    vector<vector<int>> g(n);
    for (int i = 0; i < n; i++) {
        int x1 = points[i][0];
        int y1 = points[i][1];
        for (int j = i + 1; j < n; j++) {
            int x2 = points[j][0];
            int y2 = points[j][1];
            int cost = abs(x1-x2) + abs(y1-y2);
            int id = edges.size();
            g[i].push_back(id);
            g[j].push_back(id);
            edges.push_back({i, j, cost});
        }
    }

    vector<int> order(edges.size());
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&edges](int a, int b) {
        return edges[a].cost < edges[b].cost;
    });

    int mst_weight = 0;
    DSU D;
    D.init(n);

    for (int id : order) {
        auto &e = edges[id];
        if (!D.sameSet(e.from, e.to)) {
            D.unite(e.from, e.to);
            mst_weight += e.cost;
        }
    }

    cout << mst_weight << endl;
}


int main() {

    vector<vector<int>> p {
        {0,0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}
    };

    minCostConnectPointsKruskal(p);

    return 0;
}
