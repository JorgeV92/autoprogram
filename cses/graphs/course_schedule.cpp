#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int maxn = 100006;
vector<int> g[maxn];
int in[maxn];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        in[b]++;
    }
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (!in[i])
            q.push(i);
    } 

    vector<int> topo;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        topo.push_back(v);
        for (auto u : g[v]) {
            if (--in[u] == 0) {
                q.push(u);
            }
        }
    }
    if ((int)topo.size() == n) {
        for (int x : topo) 
            cout << x + 1 << " "; 
        cout << "\n";
    } else  {
        cout << "IMPOSSIBLE\n";
    }

    return 0;
}