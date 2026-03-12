#include <iostream>
#include <vector>

using namespace std; 

vector<vector<int>> adj;
vector<int> color;

bool dfs(int v) {
    int color_u = (color[v] == 2 ? 1 : 2);
    for (int u : adj[v]) {
        if (color[u] != 0) {
            if (color[u] != color_u) 
                return false;
        } else {
            color[u] = color_u;
            if (!dfs(u)) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    adj = vector<vector<int>>(n+1);
    color = vector<int>(n+1,0);
    for (int i =0 ;i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);   
    }

    bool valid = true;
    for (int i = 1; i <= n; i++) {
        if (color[i] == 0) {
            color[i] = 1;
            if (!dfs(i)) {
                valid = false;
                break;
            }
        }
    }

    if (!valid) {
        cout << "IMPOSSIBLE\n";
    } else {
        for (int i = 1; i <= n; i++) {
            cout << color[i] << " \n"[i == n];
        }
    }

    return 0;
}