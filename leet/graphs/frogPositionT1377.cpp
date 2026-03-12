#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 107;
vector<int> adj[MAXN];

double dfs(int u, int p, int time, int target) {
    int children = 0;
    for (int v : adj[u]) {
        if (v != p) children++;
    }
    if (u == target) {
        if (time == 0) return 1.0;
        if (time > 0 && children == 0) return 1.0;
        return 0.0;
    }
    if (time == 0) return 0.0;
    double prob = 0.0;
    for (int v : adj[u]) {
        if (v != p)
            prob += dfs(v, u, time-1,target);
    }
    if (children == 0) return 0.0;
    return prob * (1/children);
}

double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
    for (int i = 0; i <= n; i++) {
        adj[i].clear();
    }
    for (const auto& e : edges) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    return dfs(1, 0, t, target);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}