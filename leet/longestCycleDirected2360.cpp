#include <iostream>
#include <vector>

using namespace std; 

vector<int> e;
vector<bool> vis;
vector<int> dist;

int dfs(int v) {
    vis[v] = true;
    int path = -1;
    int u = e[v];
    if (u != -1) {
        if (!vis[u]) {
            dist[u] = dist[v] + 1;
            path = max(path, dfs(u));
        } else if (dist[u] != -1) {
            path = max(path, dist[v] - dist[u] + 1);
        }
    }
    dist[v] = -1;
    return path;
}

int longestCycle(vector<int>& edges) {
    int N = edges.size();
    e = edges;
    vis.resize(N, false);
    dist.assign(N, -1);

    int ans = -1;
    for (int i = 0; i < N; i++) {
        if (!vis[i]) {
            ans = max(ans, dfs(i));
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie();
    return 0;       
}