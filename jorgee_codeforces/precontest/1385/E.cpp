#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define pii pair<int,int>

vector<vector<int>> g;
vector<bool> used;
vector<int> ord;

void dfs(int v) {
    used[v] = true;
    for (int u : g[v]) {
        if (!used[u])
            dfs(u);
    }
    ord.push_back(v);
}

void solve() {
    int n, m;
    cin >> n >> m;

    g = vector<vector<int>>(n);
    vector<pii> e;
    for (int i = 0; i < m; i++) {
        int t, u, v;
        cin >> t >> u >> v;
        u--; v--;
        if (t) {
            g[u].push_back(v);
        } 
        e.push_back({u, v});
        
    }

    ord.clear();
    used.assign(n, false);
    for (int i =0 ; i < n; i++) {
        if (!used[i]) {
            dfs(i);
        }
    }

    vector<int> pos(n);
    reverse(ord.begin(), ord.end());
    for (int i = 0; i < n; i++) {
        pos[ord[i]] = i;
    }

    bool bad = false;
    for (int v = 0; v < n; v++) {
        for (int u : g[v]) {
            if (pos[v] > pos[u])
                bad = true;
        }
    }

    if (bad) {
        cout << "NO" << endl;
    }  else {
        cout << "YES" << endl;
        for (auto& [u, v] : e) {
            if (pos[u] < pos[v]) {
                cout << u + 1 << " " << v + 1 << endl;
            } else {
                cout << v + 1 << " " << u + 1 << endl;
            }
        }
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
