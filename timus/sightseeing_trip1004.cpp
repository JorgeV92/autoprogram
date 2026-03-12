#include <iostream>
#include <vector>
#include <queue>

using namespace std;

using pii = pair<int,int>;
const int inf = 1e9 + 5;

vector<vector<int>> adj;
vector<int> p;
int n, m;

vector<int> get_path(int u, int v, const vector<vector<int>>& nxt) {
    vector<int> path;
    if (nxt[u][v] == -1) return path; 

    path.push_back(u);
    while (u != v) {
        u = nxt[u][v];
        path.push_back(u);
    }
    return path;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
  cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(n, inf));
    for (int i = 0; i < n; i++) g[i][i] = 0;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        if (w < g[u][v]) g[u][v] = g[v][u] = w;
    }

    vector<vector<int>> dist = g;
    vector<vector<int>> nxt(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (g[i][j] < inf && i != j) {
                nxt[i][j] = j;
            }
        }
    }

    int best = inf;
    vector<int> best_cycle;

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < k; i++) {
            for (int j = i + 1; j < k; j++) {
                if (g[i][k] < inf && g[k][j] < inf && dist[i][j] < inf) {
                    int cand = dist[i][j] + g[i][k] + g[k][j];
                    if (cand < best) {
                        best = cand;
                        auto path = get_path(i, j, nxt);
                        path.push_back(k);
                        best_cycle = path;
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (dist[i][k] == inf) continue;
            for (int j = 0; j < n; j++) {
                if (dist[k][j] == inf) continue;
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    nxt[i][j] = nxt[i][k];
                }
            }
        }
    }

    if (best == inf) {
        cout << "No solution.\n";
    } else {
        for (int v : best_cycle) cout << v + 1 << " ";
        cout << "\n";
    }




    return 0;
}