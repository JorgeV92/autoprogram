#include <iostream>
#include <vector>
#include <numeric>
#include <queue>

using namespace std;

#define vi vector<int>
#define ll long long

const int MOD = 1e9;

void addi(ll& a, ll b) {
    a *= b;
    if (a >= MOD) {
        a /= MOD;
    }
}

struct edge {
    int from;
    int to;
    int cost;
};

struct DSU {
    vi e; void init(int N) { e = vi(N, -1); }
    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
    bool sameSet(int x, int y) { return get(x) == get(y); }
    int size(int x) { return -e[get(x)]; }
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
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--; 
        int id = edges.size();
        g[u].push_back(id);
        g[v].push_back(id);
        edges.push_back({u, v, w});
    }
    vector<int> order(edges.size());
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&edges](int a, int b) {
        return edges[a].cost < edges[b].cost;
    });
    ll total_weight = 0;
    DSU D;
    D.init(n);
    int components = n-1;
    for (int id : order) {
        auto &e = edges[id];
        if (!D.sameSet(e.from, e.to)) {
            D.unite(e.from, e.to); 
            addi(total_weight, e.cost);
            n--;
        }
    }

    cout << total_weight << endl;

}

void cost(int n, int m) {
    vector<vector<int>> g(n);
    vector<edge> edges;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        int id = edges.size();
        g[u].push_back(id);
        g[v].push_back(id);
        edges.push_back({u, v, w});
    } 

    vector<ll> csum(edges.size());
    vector<int> order(edges.size());
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&edges](int a, int b) {
        return edges[a].cost < edges[b].cost;
    });
    ll prefix = 0;
    for (int id : order) {
        prefix += edges[id].cost;
        csum[id] = prefix;
    }
    sort(order.begin(), order.end(), [&edges](int a, int b) {
        return edges[a].cost > edges[b].cost;
    });

    DSU D;
    D.init(n);
    ll res = 0;
    int curr_sum = 0;
    for (int id : order) {
        auto& e = edges[id];
        if (!D.sameSet(e.from, e.to)) {
            ll f = (ll)D.size(e.from) * D.size(e.to);
            res += f * csum[id];
            D.unite(e.from, e.to);
        }
    }
    cout << res << endl;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    // kruskal(n ,m);
    cost(n, m);

    return 0;
}