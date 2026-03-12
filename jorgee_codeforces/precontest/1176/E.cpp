#include <iostream>
#include <vector>
#include <queue>

using namespace std;


constexpr int MAXN = 2e5 + 2;
constexpr int MAXM = 2e5 + 2;
using ll = long long;

vector<int> e[MAXN];
ll dist[MAXM];

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        e[i].clear();
        dist[i] = 0;
    }

    for (int i =0 ; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    vector<bool> vis(n, false);
    queue<int> q;
    q.push(0);
    vis[0] = true;
    dist[0] = 0;

    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto u : e[v]) {
            if (!vis[u]) {
                dist[u] = dist[v] + 1;
                vis[u] = true;
                q.push(u);
            }
        }
    }

    vector<int> odd, even;
    for (int i = 0; i < n; i++) {
        if (dist[i] & 1) {
            odd.push_back(i);
        } else {
            even.push_back(i);
        }
    }
    if (odd.size() < even.size()) {
        cout << odd.size() << endl;
         for (int v : odd) {
            cout << v + 1 << " ";
         }
         cout << endl;
    } else {
        cout << even.size() << endl;
        for (int v : even) {
            cout << v + 1 << " ";
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}