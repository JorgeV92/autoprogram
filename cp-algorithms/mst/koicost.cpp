#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1000000000;

vector<int> parent, rnk, sz;
long long sum[1000009];

void make_set(int v) {
    parent[v] = v;
    rnk[v] = 0;
    sz[v] = 1;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rnk[a] < rnk[b]) 
            swap(a, b);
        sz[a] += sz[b];
        parent[b] = a;
        if (rnk[a] == rnk[b]) 
            rnk[a]++;
    }
}

struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) const {
        return weight < other.weight;
    }
};

int n, m;
vector<Edge> edges;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    parent.resize(n+1);
    rnk.resize(n+1);
    sz.resize(n+1);
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        edges.push_back({a, b, w});
    }
    sort(edges.begin(), edges.end());
    for (int i = 0; i < m; i++) 
        sum[i] = edges[i].weight + (i > 0 ? sum[i-1]: 0);
    for (int i = 1; i <= n; i++) {
        make_set(i);
    }

    long long cost = 0, su= 0, sv= 0;
    for (int i = m-1; i >= 0; i--) {
        int u = find_set(edges[i].u);
        int v = find_set(edges[i].v);
        if (u != v) {
            su = sz[u]; sv = sz[v];
            cost += (su * sv) * sum[i];
            union_set(u, v);
        }
    }
    cout << cost << '\n';

    return 0;
}

/*

        int n = points.size();
        vector<vector<int>> adj(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            int x = points[i][0];
            int y = points[i][1];
            for (int j = i+1; j < n; j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];
                int d = abs(x - x2) + abs(y - y2);
                adj[i][j] = d;
                adj[j][i] = d;
            }
        }

        int total_weight = 0;
        vector<bool> selected(n);
        vector<Edge> min_e(n);
        min_e[0].w = 0;

        for (int i = 0; i < n; i++) {
            int v = -1;
            for (int j = 0; j < n; j++) {
                if (!selected[j] && (v == -1 || min_e[j].w < min_e[v].w)) {
                    v = j;
                }
            }

            selected[v] = true;
            total_weight += min_e[v].w;
            for (int to = 0; to < n; to++) {
                if (adj[v][to] < min_e[to].w) {
                    min_e[to] = {adj[v][to], v};
                }    
            }
        }

        return total_weight;
*/