#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

#define vi vector<int>
#define ll long long
#define pii pair<int, int>

struct edge {
    int w;
    int u;
    int v;
    bool operator<(const edge& other) const {
        return w < other.w;
    }
};

ll res;

struct DSU {
    vi e; void init(int N) { e = vi(N,-1); }
    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
    bool sameSet(int x, int y) { return get(x) == get(y); }
    int size(int x) { return -e[get(x)]; }
    ll calc(int n) { return 1ll * n *(n-1)/2; }
    bool unite(int x, int y) {
        x = get(x); y = get(y);
        if (x == y) return false;
        res -= calc(size(x));
        res -= calc(size(y));
        // res += (1ll * size(x) * size(y));
        if (e[x] > e[y]) swap(x, y);
        e[x] += e[y];
        e[y] = x;
        res += calc(size(x));
        return true; 
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<edge> edges(n-1);
    for (int i = 0; i < n-1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        edges[i] = {w, u, v};
    }

    vector<pii> queries(m);
    for (int i = 0; i < m; i++) {
        cin >> queries[i].first;
        queries[i].second = i;
    }

    sort(edges.begin(),edges.end());
    sort(queries.begin(), queries.end());

    DSU D;
    D.init(n);
    vector<ll> ans(m);
    int pos = 0;
    for (int i = 0; i < m; i++) {
        while (pos < n-1 && edges[pos].w <= queries[i].first) {
            int u = edges[pos].u;
            int v = edges[pos].v;
            D.unite(u, v);
            pos++;
        }
        ans[queries[i].second] = res;
    }

    for (int i = 0; i < m; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;


    return 0;
}