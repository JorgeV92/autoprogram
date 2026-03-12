#include <iostream>
#include <vector>

using namespace std; 

constexpr int MAXN = 2e5 + 9;
vector<int> adj[MAXN];
int dist[MAXN];

void dfs(int v, int p) {
    for (int u : adj[v]) {
        if (u != p) {
            dist[u] = dist[v] + 1;
            dfs(u, v);
        } 
    }
} 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i <= n; i++) {
        adj[i].clear();
        dist[i] = 0;
    }

    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);

    int mx = 0;
    int node = -1;
    for (int i = 1; i <= n; i++) {
        if (mx < dist[i]) {
            mx = dist[i];
            node = i;
        }
    }

    fill(dist, dist+n+1, 0);

    dfs(node, 0);

    mx = 0;
    for (int i = 1; i <= n; i++) {
        if (mx < dist[i]) {
            mx = dist[i];
        }
    }
    cout << mx << endl;

    return 0;
}