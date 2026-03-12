#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

const int N = 300001;

int dp[N][26];
vector<int> adj[N];
int ind[N];


int main() {    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        ind[b]++;
    }

    queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (!ind[i]) {
            q.push(i);
            dp[i][s[i-1]-'a'] = 1;
        }
    }

    int nodes = n;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        nodes--;
        for (int u : adj[v]) {
            for (int j = 0; j < 26; j++) {
                dp[u][j] = max(dp[u][j], dp[v][j] + (s[u-1]-'a' == j));
            }
            ind[u]--;
            if (!ind[u]) 
                q.push(u);
        }
    }

    if (nodes) {
        cout << -1 << endl;
        return 0;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 26; j++) {
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans << endl;

    return 0;   
}