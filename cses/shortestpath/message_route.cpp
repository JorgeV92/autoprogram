#include <iostream>
#include <vector>
#include <queue>

using namespace std;

constexpr int inf = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> d(n, -1);
    vector<int> p(n, -1);
    queue<int> q;
    q.push(0);
    d[0] = 0;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : g[v]) {
            if (d[u] == -1) {
                d[u] = d[v] + 1;
                p[u] = v;
                q.push(u);
            }
        }
    }

    if (d[n-1] == -1)  {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << d[n-1] + 1 << endl;
        vector<int> path;
        for (int v = n-1; v != 0; v = p[v]) {
            path.push_back(v);
        }
        path.push_back(0);
        reverse(path.begin(), path.end());
        for (int x : path) {
            cout << x + 1 << " ";
        }
        cout << endl;
    }

    return 0;
}