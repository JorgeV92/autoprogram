#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <cstring>

using namespace std;

#define NINF INT_MIN
#define pii pair<int,int>

constexpr int N = 1009;

vector<pii> adj[N];
int dist[N];
vector<bool> vis;
vector<int> topo;

void dfs(int v) {
    vis[v] = true;
    for (const auto& [u, w] : adj[v]) {
        if (!vis[u]) 
            dfs(u);
    }
    topo.push_back(v);
}

vector<int> maximumDistance(vector<vector<int>> edges, int v, int e, int src) {
    for (int i = 0; i < v; i++) {
        adj[i].clear();
    }
    for (const auto& e : edges) {
        int u = e[0];
        int v = e[1];
        int w = e[2];
        adj[u].push_back({v, w});
    }
    vis.assign(v, false);
    dfs(src);
    for (int i = 0; i < v; i++) 
        dist[i] = NINF;

    dist[src] = 0;
    reverse(topo.begin(), topo.end());
    for (int i = 0; i < topo.size(); i++) {
        int v = topo[i];
        if (dist[v] != NINF) {
            for (const auto& [u, w] : adj[v]) {
                if (dist[u] < dist[v] + w) {
                    dist[u] = dist[v] + w;
                }
            }
        }
    }

    vector<int> ans;
    for (int i  = 0 ;i < v; i++) {
        if (dist[i] == NINF) {
            ans.push_back(INT_MIN); 
        } else {
            ans.push_back(dist[i]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
}
