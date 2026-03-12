#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

#define vi vector<int>
#define pii pair<int,int>

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

vector<vector<pii>> g;
vector<vector<int>> dist;
vector<edge> edges;
int n;

void kruskal(vector<edge>& edges) {
    int added = 0;
    DSU D;
    D.init(n);
    sort(edges.begin(), edges.end(), [&edges](const auto& a, const auto& b) {
        return a.cost < b.cost;
    });
    for (const auto& e : edges) {
        if (!D.sameSet(e.from, e.to)) {
            D.unite(e.from, e.to);
            added++;
            g[e.from].push_back({e.to, e.cost});
            g[e.to].push_back({e.from, e.cost});
            if (added == n-1)
                goto end;
        }
    }
end:;
}

int dfs(int u, int p, int src, int d) {
    if (dist[src][u] != d || (src != u && dist[src][u] == 0)) return false;
    bool valid = true;
    for (const auto& e : g[u]) {
        if (e.first == p) continue;
        valid &= dfs(e.first, u, src, d + e.second); 
    }
    return valid;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    g = vector<vector<pii>>(n);
    dist = vector<vector<int>>(n, vector<int>(n));

    bool valid = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
            if (i == j) {
                if (dist[i][j] != 0) {
                    valid = false;
                }
            }  else {
                if (j < i && dist[i][j] != dist[j][i]) valid = false;
                if (i < j) {
                    edges.push_back({i, j, dist[i][j]});
                } 
            }
        }
    }
    
    kruskal(edges);

    for (int i = 0; i < n; i++) {
        valid &= dfs(i, -1, i, 0);
    }

    if (valid) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
