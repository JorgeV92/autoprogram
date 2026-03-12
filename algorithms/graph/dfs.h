#include <vector>

std::vector<std::vector<int>> adj;
std::vector<int> visited;
int n;

void dfs(int v) {
    visited[v] = true;
    for (auto u : adj[v]) {
        if (!visited[u]) {
            dfs(u);
        }
    }
}

std::vector<int> color;
std::vector<int> time_in, time_out;
int dfs_timer = 0;

void dfs_t(int v) {
    time_in[v] = dfs_timer++;
    color[v] = 1;
    for (auto u : adj[v]) {
        if (color[u] == 0) 
            dfs(u);
    }
    color[v] = 2;
    time_out[v] = dfs_timer++;
}