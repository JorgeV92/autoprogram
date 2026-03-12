#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std; 

constexpr int MAXN = 2e5+7;
vector<int> adj[MAXN];
int dist[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> T(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> T[i];
    }
    for (int i = 0; i <= n; i++) {
        adj[i].clear();
    }
    memset(dist, -1, sizeof(dist));
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dist[1] = 0;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : adj[v]) {
            if (dist[u] == -1) {
                dist[u] = dist[v] + 1;
                q.push(u);
            }
        }
    }
    vector<int> ans(k+1,0);
    for (int i = 1; i <= n; i++) {
        int t = T[i];
        if (dist[i] != -1) {
            ans[t] = max(ans[t], dist[i]);
        } 
    }

    for (int i = 1; i <= k; i++) {
        cout << ans[i] << " \n"[i == k];
    }

    return 0;
}