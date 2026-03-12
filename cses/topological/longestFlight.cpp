#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

#define NINF INT_MIN

constexpr int N = 100003;
vector<int> adj[N], rev[N];
int ind[N], dist[N];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        adj[i].clear();
        ind[i] = 0;
        dist[i] = NINF;
    }
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        rev[b].push_back(a);
        ind[b]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (!ind[i])
            q.push(i);
    }

    vector<int> topo;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        topo.push_back(v);
        for (int u : adj[v]) {
            ind[u]--;
            if (!ind[u])
                q.push(u);
        }
    }

    vector<int> p(n, -1);
    dist[0] = 1;
    for (int i = 0; i < (int)topo.size(); i++) {
        int v = topo[i];
        for (int u : rev[v]) {
            if (dist[v] < dist[u] + 1) {
                dist[v] = dist[u] + 1;
                p[v] = u;
            }
        }
    }

    if (dist[n-1] < 0) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << dist[n-1] << endl;
        vector<int> path;
        for (int v = n-1;  v != 0; v = p[v]) {
            path.push_back(v);
        }
        path.push_back(0);
        reverse(path.begin(), path.end());
        for (int i = 0; i < (int)path.size(); i++) {
            cout << path[i] + 1 << " \n"[i+1==(int)path.size()];
        }
    }

    return 0;
}