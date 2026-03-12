#include <iostream>
#include <vector>
#include <queue>

using namespace std; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> dist(n,-1);
    vector<int> p(n, -1);
    queue<int> q;
    q.push(0);
    dist[0] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : adj[v]) {
            if (dist[u] == -1) {
                dist[u] = dist[v] + 1;
                p[u] = v;
                q.push(u); 
            }
        }
    }

    if (dist[n-1] == -1) {
        cout << "Impossible\n";
    } else {
        vector<int> path;
        for (int v = n-1; v != 0; v = p[v]) {
            path.push_back(v);
        }
        path.push_back(0);
        reverse(path.begin(), path.end());
        cout << dist[n-1] + 1 << endl;
        for (int i = 0; i < path.size(); i++) {
            cout << path[i] + 1 << " \n"[i+1==path.size()];
        }
    }

    return 0;
}   
