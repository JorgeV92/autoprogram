#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <numeric>

using namespace std;

const int INF = 1e9 + 7;
using pii = pair<int,int>;

struct Edge {
    int to = -1;
    int w = INF;
    bool operator <(Edge const& other) const {
        return make_pair(w, to) < make_pair(other.w, other.to);
    }
};

vector<vector<Edge>> adj;
vector<vector<pair<int,int>>> G; 

int prim_set() {
    const int n = adj.size();
    vector<int> visited(n);
    vector<Edge> min_e(n);
    set<Edge> q;
    int total_weight = 0;
    min_e[1].w = 0;
    q.insert({0, 1});
    for (int i = 0; i < n; i++) {
        if (q.empty()) {
            cout << "IMPOSSIBLE\n";
            exit(0);
        }

        int v = q.begin()->to;
        visited[v] = true;
        total_weight += q.begin()->w;
        q.erase(q.begin());
        
        for (Edge e : adj[v]) { 
            if (!visited[e.to] && e.w < min_e[e.to].w) {
                q.erase({min_e[e.to].w, e.to});
                min_e[e.to] = {e.w, v};
                q.insert({e.w, e.to});
            }
        } 
    }
    return total_weight;
}

int prim_queue() {
    const int n = G.size();
    vector<bool> visited(n);
    vector<int> min_e(n, INF);
    min_e[1] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 1});

    int total_weight = 0;
    int added = 0;
    while (added < n-1) {
        if (pq.empty()) {
            cout << "IMPOSSIBLE\n";
            exit(0);    
        }
        auto [curr_cost, v] = pq.top();
        pq.pop();
        if (min_e[v] < curr_cost) continue;
        added++;
        total_weight += curr_cost;
        visited[v] = true;
        for (auto& edge : G[v]) {
            int to = edge.first;
            int len = edge.second;
            
            if (!visited[to] && len < min_e[to]) {
                min_e[to] = len;
                pq.push({len, to});
            }
        }
    }

    return total_weight;
}

struct edge {
    int from;
    int to;
    int cost;
};

struct DSU {
    vector<int> e; void init(int N) { e = vector<int>(N, -1); }
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

void kruskal(int n, int m) {
    vector<edge> edges;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        a--; b--;
        int id = edges.size();
        g[a].push_back(id);
        g[b].push_back(id);
        edges.push_back({a, b, w});
    };

    vector<int> order(edges.size());
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&edges](int a, int b) {
        return edges[a].cost < edges[b].cost;
    });
    
    int total_weight = 0;
    DSU D;
    D.init(n);
    int components = n-1;
    for (int id : order) {
        auto& e = edges[id];
        if (!D.sameSet(e.to, e.from)) {
            D.unite(e.from, e.to);
            total_weight += e.cost;
            n--;
        }
    }

    if (n != 1) {
        cout << "IMPOSSIBLE\n";
        return;
    } else {
        cout << total_weight << endl;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    
    // //adj.assign(n+1, {});
    // G.assign(n+1, {});
    // for (int i = 0; i < m; i++) {
    //     int a, b, w;
    //     cin >> a >> b >> w;
    //     G[a].push_back({b, w});
    //     G[b].push_back({a, w});
    // }  

    // int mst_weight = prim_queue();

    // cout << mst_weight << endl;

    kruskal(n, m);

    return 0;
}
