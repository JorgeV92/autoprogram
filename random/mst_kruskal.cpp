#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cassert>

using namespace std;

#define vi vector<int>

template<typename T> 
class Graph {
public:
    struct edge {
        int from;
        int to;
        T cost;
    };

    vector<edge> edges;
    vector<vector<int>> g;
    int n;

    Graph(int _n) : n(_n) {
        g.resize(n);
    }

    virtual int add(int from, int to, T cost) = 0;
};

template<typename T> 
class UndiGraph : public Graph<T> {
public:
    using Graph<T>::edges;
    using Graph<T>::g;
    using Graph<T>::n;

    UndiGraph(int _n) : Graph<T>(_n) {}

    int add(int from, int to, T cost=1) {
        assert(0 <= from && from < n && 0 <= to && to < n);
        int id = (int)edges.size();
        g[from].push_back(id);
        g[to].push_back(id);
        edges.push_back({from, to, cost});
        return id;
    }
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

template<typename T> 
vector<int> find_mst(const UndiGraph<T>& g, T &ans) {
    vector<int> order(g.edges.size());
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&g](int a, int b) {
        return g.edges[a].cost < g.edges[b].cost;
    });
    DSU D;
    D.init(g.n);
    vector<int> ans_list;
    ans = 0;
    for (int id : order) {
        auto &e = g.edges[id];
        if (!D.sameSet(e.from, e.to)) {
            D.unite(e.from, e.to);
            ans_list.push_back(id);
            ans += e.cost;
        }
    }
    return ans_list;
}


int main() {
    // 1584. Min Cost to Connect All Points
    vector<vector<int>> points{
        {0,0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}
    };
    const int n = points.size();
    UndiGraph<int> G(n);

    for(int i = 0; i < n; i++) {
        int x1 = points[i][0];
        int y1 = points[i][1];
        for (int j = i+1; j < n; j++) {
            int x2 = points[j][0];
            int y2 = points[j][1];
            // Manhattan distance
            int d = abs(x1 - x2) + abs(y1 - y2);
            G.add(i, j, d);
        }
    }

    int mst;
    auto path = find_mst(G, mst);
    cout << mst << endl;

    return 0;
}


