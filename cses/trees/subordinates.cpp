#include <iostream>
#include <vector>

using namespace std;

constexpr int MAXN = 2e5 + 1;
vector<int> adj[MAXN];
int dist[MAXN];

void dfs(int v) {
    for (auto u : adj[v]) {
        dfs(u);
        dist[v] += dist[u] + 1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    for (int i = 2; i <= n; i++) {
        int a;
        cin >> a;
        adj[a].push_back(i);
    } 

    dfs(1);

    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }

    return 0;
}