#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
int M;
vector<vector<int>> adj;
vector<bool> vis;
vector<int> bfs_edges;

void dfs(int v) {
    vis[v] = true;
    for (int u : adj[v]) {
        if (!vis[u]) {
            dfs(u); 
        }
    }
}

void bfs() {
    for (int i = 0; i < N; i++) {
        if (!vis[i]) {
            vis[i] = true;
            bfs_edges.push_back(i);
            queue<int> q;
            q.push(i);
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                for (int u : adj[v]) {
                    if (!vis[u]) {
                        vis[u] = true;
                        q.push(u);
                    }
                }
            }
        }

    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    N = n; 
    M = m;

    adj = vector<vector<int>>(n, vector<int>(m));
    vis = vector<bool>(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int components = 0;
    vector<int> edges;
    for (int i = 0; i < n; i++) { 
        if (!vis[i]) {
            dfs(i);
            components++;
            edges.push_back(i);
        }
    }    


    cout << edges.size() - 1 << endl;
    for (int i = 0; i < edges.size()-1; i++) {
        cout << edges[i] + 1 << " " << edges[i+1] + 1;
        cout << endl;
    }
    cout << endl;
    

    return 0;
}
