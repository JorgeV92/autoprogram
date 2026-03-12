#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    string word;
    cin >> word;
    vector<vector<int>> adj(n);
    vector<int> indegree(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        indegree[b]++;
    }

    queue<int> q;
    // dp[i][j] is the frequency of letter j when at node i.
    vector<vector<int>> dp(n, vector<int>(26));
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
            dp[i][word[i] - 'a']++;
        }
    }
    vector<int> topo;
    int size = 0;
    while (size < n && !q.empty()) {
        int v = q.front(); 
        q.pop();
        topo.push_back(v);
        for (int u : adj[v]) {
            for (int j = 0; j < 26; j++) {
                if (j ==(word[u] - 'a')) {
                    dp[u][j] = max(dp[v][j] + 1, dp[u][j]);
                } else {
                    dp[u][j] = max(dp[v][j], dp[u][j]);
                }
            }

            if (--indegree[u] == 0) {
                q.push(u);
            }
        }
        size++;
    }

    if (size < n) {
        cout << -1 << endl;
        return 0;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 26; j++) {
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;

    return 0;
}