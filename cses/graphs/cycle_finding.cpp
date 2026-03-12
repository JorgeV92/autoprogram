#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct edge {
    int a, b;
    int64_t w;
};

const int64_t inf = 1e18;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<edge> edges(m);
    for (int i = 0 ; i < m; i++) {
        int a, b;
        int64_t w;
        cin >> a >> b >> w;
        a--, b--;
        edges[i] = {a, b, w};
    }
    vector<int64_t> d(n, 0);
    vector<int> p(n, -1);
    int x;
    for (int i = 0; i < n; i++) {
        x = -1;
        for (auto e : edges) {
            if (d[e.a] + e.w < d[e.b]) {
                d[e.b] = max(-inf, d[e.a] + e.w);
                p[e.b] = e.a;
                x = e.b;
            }
        }
    }

    if (x == -1) {
        cout << "NO\n";
    } else {
        for (int i = 0; i < n; i++) x = p[x];
        vector<int> cycle;
        for (int v = x; ; v = p[v]) {
            cycle.push_back(v);
            if (v == x && cycle.size() > 1) break;
        }
        reverse(cycle.begin(), cycle.end());
        cout << "YES\n";
        for (auto x : cycle) {
            cout << x + 1 << " ";
        }
        cout << "\n";
    }

    return 0;
}