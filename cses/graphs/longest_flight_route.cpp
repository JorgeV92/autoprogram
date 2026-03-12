#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9 + 5;

int main() {

    int n, m;
    cin >> n >> m;
   
    vector<vector<int>> adj(n+1), back_edge(n+1); 
    vector<int> indegree(n+1);
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        
        adj[a].push_back(b);
        back_edge[b].push_back(a);
        indegree[b]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) 
            q.push(i);
    }     

    vector<int> topo;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        topo.push_back(u);
        for (int v : adj[u]) {
            if (--indegree[v] == 0) {
                q.push(v);
            }
        }
    }
        
    // Find the longest path using topological ordering
    // since we have a DAG no cycles can do dp.
    vector<int> parent(n+1, -1);
    // dist[u] - is the maximum number of cities on a valid path from 1 to u
    vector<int> dist(n+1, -INF);
    dist[1] = 1;
    for (int i = 0; i < topo.size(); i++) {
        int u = topo[i];
        for (int v : back_edge[u]) { // v -> u in the original graph
            if (dist[v] + 1 > dist[u]) {
                dist[u] = dist[v] + 1;
                parent[u] = v;
            }
        } 
    }    


    if (dist[n] < 0) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << dist[n] << endl;

        vector<int> path;
        for (int at = n; at != 1; at = parent[at] ) {
            path.push_back(at);            
        }
        path.push_back(1);
        reverse(path.begin(), path.end());
        
        for (int x : path) {
            cout << x << " ";
        }
        cout << endl;
    }


    return 0;
}
