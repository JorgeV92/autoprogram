#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[100];

vector<int> bfs(int u) {
    int V = 100;
    vector<bool> vis(V);
    vector<int> ans;
    queue<int> q;
    q.push(u);
    vis[u] = true;
    while (!q.empty()) {
        int v = q.front(); 
        q.pop();
        ans.push_back(v);
        for (int nxt : adj[v]) {
            if (!vis[nxt]) {
                q.push(nxt);
                vis[nxt] = true;
            }
        }
    }
    return ans;
}

void bfsAll(int u, vector<bool>& vis, vector<int>& res) {
    queue<int> q;
    q.push(u);
    vis[u] = true;
    while (!q.empty()) {
        int v = q.front(); 
        q.pop();
        res.push_back(v);
        for (int nxt : adj[v]) {
            if (!vis[nxt]) {
                vis[nxt] = true;
                q.push(nxt);
            }
        }
    }
}   

int main() {    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    adj[0] = {1, 2};
    adj[1] = {0, 2};
    adj[2] = {0, 1, 3, 4};
    adj[3] = {2};
    adj[4] = {2};

    vector<int> ans = bfs(0);
    for (int x : ans) {
        cout << x << " "; 
    }
    cout << endl;
    int V = 5;
    vector<int> res;
    vector<bool> vis(V);
    for (int i =0 ; i < V; i++) {
        if (!vis[i]) {
            bfsAll(i, vis, res);
        }
    }
    return 0;
}