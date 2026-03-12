#include <iostream>
#include <vector>

using namespace std; 

vector<vector<int>> adj;
vector<int> vis;
vector<int> dis;

int dfs(int v) {
    vis[v] = true;
    int path = -1;
    for (int u : adj[v]) {
        if (!vis[u]) {
            dis[u] = dis[v] + 1;
            path = max(path, dfs(u));
        } else if (dis[u] != -1) {
            path = max(path, dis[v] - dis[u] + 1);
        }
    }
    dis[v] = - 1;
    return path;
}

int longestCycle(vector<vector<int>>& graph) {
    int V = graph.size();
    vis.resize(V, false);
    dis.assign(V, -1);

    int ans = -1;
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            dis[i] = 0;
            ans = max(ans, dfs(i));
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}