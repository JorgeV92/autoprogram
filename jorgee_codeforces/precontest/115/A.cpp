#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
int max_depth;

int dfs(int v) {
    int max_depth = 0;
    for (int u : adj[v]){
        max_depth = max(max_depth, dfs(u));
    }
    return 1 + max_depth;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> roots;
    max_depth = 0;
    adj = vector<vector<int>>(n+1);
    for (int i = 1; i <= n; i++) {
        int p;
        cin >> p;
        if (p == -1) {
            roots.push_back(i);
        } else {
            adj[p].push_back(i);
        }
    }
    int ans = 0;
    for (int v : roots) {
        ans = max(ans, dfs(v));
    }

    cout << ans << endl;

    return 0;
}