#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define pii pair<int,int>

vector<vector<pii>> adj;
vector<bool> vis;
int total, K;

void dfs(int v) {
    vis[v] = true;
    for (const auto& [u ,w] : adj[v]) {
        if (!vis[u] && w >= K) {
            total++;
            dfs(u);
        }
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    
    adj = vector<vector<pii>>(N+1);
    for (int i = 0; i < N-1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // run dfs
    // for (int i =0 ; i < Q; i++) {
    //     int k, v;
    //     cin >> K >> v;
    //     total = 0;
    //     vis.assign(N+1, false);
    //     dfs(v);
    //     cout << total << endl;
    // }

    // run bfs
    for (int i = 0; i < Q; i++) {
        int v;
        cin >> K >> v;
        vis.assign(N+1, false);
        total = 0;
        queue<int> q;
        q.push(v);
        vis[v] = true;

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (const auto& [u, w] : adj[v]) {
                if (!vis[u] && w >= K) {
                    vis[u] = true;
                    total++;
                    q.push(u);
                }
            }
        }

        cout << total << endl;
        
    }

    return 0;
}