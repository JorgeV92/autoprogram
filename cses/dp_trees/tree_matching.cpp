#include <iostream>
#include <vector>

using namespace std;


const int MAX = 2000001;
vector<vector<int>> adj(MAX);
vector<vector<int>> dp(MAX, vector<int>(2));

void dfs(int v, int p) {
    for (int to : adj[v]) {
        if (to == p) continue;
        dfs(to, v);
        dp[v][0] += max(dp[to][1], dp[to][0]);
    } 

    for (int to : adj[v]) {
        if (to == p) continue;
        dp[v][1] = max(dp[v][1], dp[to][0] + 1 + dp[v][0] - max(dp[to][0] ,dp[to][1]));
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(0, -1);
    cout << max(dp[0][0], dp[0][1]) << endl;

    return 0;
}
