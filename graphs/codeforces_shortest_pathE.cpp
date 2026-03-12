#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <tuple>
#include <set>
#include <algorithm>


using namespace std;




int main() {
    
    int n, m, k;
    cin >> n >> m >> k;
        

    vector<vector<int>> adj(n+1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    set<tuple<int,int,int>> forbidden;

    for (int i = 0; i < k; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        forbidden.insert(make_tuple(a, b, c));
    }

    // BFS
    vector<bool> vis(n+1,false);
    vector<int> d(n+1);
    vector<int> p(n+1, -1); 
    
    queue<pair<int,int>> q;
    q.push({1, -1});
    d[1] = 0;
    vis[1] = true;
    

    while (!q.empty()) {
        // u is curr and v is prev
        auto [u , v] = q.front(); q.pop();

        for (int c : adj[u]) {
            auto triplet = make_tuple(v, u, c);
            auto it = forbidden.find(triplet);
            if (it != forbidden.end()) continue;

            if (!vis[c]) {
                vis[c] = true;
                d[c] = d[u] + 1;
                q.push({c, u});
                p[c] = u; 
            }
        }
    }

    if (!vis[n]) {
        cout << "-1\n";
        return 0; 
    }

    vector<int> path;
    for (int v = n; v != 1; v = p[v]) {
        path.push_back(v);
    }
    path.push_back(1);

    reverse(path.begin(), path.end());
    
    cout << path.size() - 1 << endl;
    for (int v : path) {
        cout << v << " ";
    }

    cout << endl;


    return 0;    
}
