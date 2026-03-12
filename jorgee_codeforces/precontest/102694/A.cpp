#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 3e5 + 4;

vector<int> adj[N];

int f[N];  
int g[N];
int diameter;

void dfs(int u, int p) {
    vector<int> fValues;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        fValues.push_back(f[v]);
    }
    sort(fValues.begin(), fValues.end());

    f[u] = 0;
    if (!fValues.empty()) {
        f[u] = 1 + fValues.back();
    }

    if (fValues.size() >= 2) {
        g[u] = 2 + fValues.back() + fValues[fValues.size() - 2];
    }

    diameter = max(diameter, max(f[u], g[u]));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }

    for (int i = 1; i <= n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    diameter = 0;
    dfs(1, 0);

    cout << 3 * diameter << endl;

    return 0;
}