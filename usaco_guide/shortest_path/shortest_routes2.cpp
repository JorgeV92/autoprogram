#include <iostream>
#include <vector>

using namespace std;

#define pii pair<int,int>
using i64 = long long;

constexpr i64 INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<i64>> dist(n+1, vector<i64>(n+1, INF));
    for (int i = 1; i <= n; i++) dist[i][i] = 0;
    for (int i = 0; i < m; i++) {
        int u, v , w;
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], (i64)w);
        dist[v][u] = min(dist[v][u], (i64)w);
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(
                    dist[i][j],
                    dist[i][k] + dist[k][j]
                );
            }
        }
    }

    while (q--) {
        int u, v;
        cin >> u >> v;
        if (dist[u][v] != INF) {
            cout << dist[u][v] << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}
