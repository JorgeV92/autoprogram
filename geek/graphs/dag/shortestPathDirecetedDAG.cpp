#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <stack>

using namespace std;

#define pii pair<int,int>

constexpr int inf = 1e9;
constexpr int N = 1009;

vector<pii> adj[N];
int dist[N];
vector<bool> vis;
stack<int> st;

void dfs(int v) {
    vis[v] = true;
    for (const auto& [u, w] : adj[v]) {
        if (!vis[u]) 
            dfs(u);
    }
    st.push(v);
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
    dfs(0);
    for (int i = 0; i < v; i++) 
        dist[i] = inf;

    dist[0] = 0;
    while (!st.empty()) {
        int v = st.top();
        st.pop();
        if (dist[v] != inf) {
            for (const auto& [u, w] : adj[v]) {
                if (dist[u] > dist[v] + w) {
                    dist[u] = dist[v] + w;
                }
            }
        }
    }

    vector<int> ans;
    for (int i = 0; i < v; i++) {
        if (dist[i] == inf) {
            ans.push_back(-1);
        } else {
            ans.push_back(dist[i]);
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}