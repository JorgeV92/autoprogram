#include <iostream>
#include <vector>

using namespace std;

using i64 = long long;
constexpr i64 inf = 1e18; 
i64 dist[505][505];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i==j) {
                dist[i][i] = 0;
            } else {
                dist[i][j] = inf;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        a--; b--;
        dist[a][b] = min(dist[a][b], (i64)w);
        dist[b][a] = min(dist[b][a], (i64)w);
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }


    while (q--) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        
        if (dist[u][v] == inf) {
            cout << -1 << endl;
        } else {
            cout << dist[u][v] << endl;
        }
    }
    return 0;
}
