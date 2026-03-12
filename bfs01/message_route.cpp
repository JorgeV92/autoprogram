#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// we use a 0/1BFS solution 

int main() {

    int N, M;
    cin >> N >> M;
    vector<int> dist(N+1, INT_MAX);
    vector<int> parent(N+1);
    vector<vector<int>> adj(N+1);    

    while (M--) { 
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<int> q;
    dist[1] = 0;
    q.push(1);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (dist[v] == INT_MAX) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }


    if (dist[N] == INT_MAX) { 
        cout << "IMPOSSIBLE\n";
    } else {
        // since we want the number of computers 
        // and the dist[N] count the edges we need 
        // the plus 1 here to account the node not just 
        // edges L. A path with L edges has L + 1 nodes. 
        cout << dist[N] + 1 << endl; 
        vector<int> path;
        for (int v = N; v != 1; v = parent[v]) {
            path.push_back(v);
        } 
        path.push_back(1);
        reverse(path.begin(), path.end());
        for (int u : path) {
            cout << u << " ";
        }
        cout << endl;
    }
    
    
    return 0;
}
