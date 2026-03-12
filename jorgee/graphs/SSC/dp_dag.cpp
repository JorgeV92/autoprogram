// Longest path in a directed Acyclic graph 
//
// Find the length of the longest directed path in G
// Note: Length of a directed path is the number of edges in it.
//
//  Time O(N + M)
//  Space O(N)

#include <iostream>
#include <vector>

using namespace std;

constexpr int N = 500;
vector<int> adj[N];
int dp[N];

void dfs(int v, vector<bool>& vis) {
    vis[v] = true;
    for (int u : adj[v]) {
        if (!vis[u]) {
            dfs(v, vis);
        }
        dp[v] = max(dp[v], 1 + dp[u]);
    }
}

int find_longest_path() {
    vector<bool> vis(N);
    for (int i = 0; i < N; i++) {
        if (!vis[i])
            dfs(i, vis);
    }
    int ans = 0;
    for (int i = 0 ; i < N; i++) {
        ans = max(ans, dp[i]);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}
