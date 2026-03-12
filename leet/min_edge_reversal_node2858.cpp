#include <iostream>
#include <vector>

using namespace std;

#define pii pair<int,int>

vector<vector<pii>> adj;
vector<int> dp;

void dfs_front(int v, int parent, int& w) {
    for (const auto& [u, d] : adj[v]) {
        if (u == parent) continue;
        if (d) {
            w++;
        }
        dfs_front(u, v, w);
    }
}

void dfs_back(int v, int parent) {
    for (const auto& [u, d] : adj[v]) {
        if (u == parent) continue;
        if (!d) {
            dp[u] = dp[v] + 1;
        } else {
            dp[u] = dp[v] - 1;
        }
        dfs_bacK(u, v);
    }
}

vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
    adj = vector<vector<pii>>(n);
    dp = vector<int>(n);
    for (const auto& e : edges) {
        adj[e[0]].push_back({e[1], 0});
        adj[e[1]].push_back({e[0], 1});
    }

    int w = 0;
    dfs_front(0, -1, w);
    dp[0] = w;
    dfs_back(0, -1);
    return dp;
}

int main() {
    

    return 0;
}
