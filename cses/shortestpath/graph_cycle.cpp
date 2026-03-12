#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> adj;
const int inf = 1e9;
int n, m;

int solve(int s) {
    vector<int> d(n, -1);
    vector<int> p(n, -1);
    queue<int> q;

    d[s] = 0;
    q.push(s);
    int cycle = inf;
    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int u : adj[v]) {
            if (d[u] == -1) {
                d[u] = d[v] + 1;
                p[u] = v;
                q.push(u);
            } else if (p[v] != u) {
                cycle = min(cycle, d[u] + d[v] + 1);
            }
        }
    }
    return cycle;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    adj = vector<vector<int>>(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >>b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int min_cycle = inf;
    for (int i = 0; i < n; i++) {
        min_cycle = min(min_cycle, solve(i));
    }

    if (min_cycle == inf) {
        cout << -1 << endl;
    } else {
        cout << min_cycle << endl;
    }

    return 0;
}