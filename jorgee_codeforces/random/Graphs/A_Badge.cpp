#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

constexpr int N = 1009;
int color[N];
int p[N];
int out[N];

void dfs(int v, vector<int>& path) {
    color[v] = 1;
    path.push_back(v);
    int u = p[v];
    if (color[u] == 1) {
        int cycle = false;
        for (int nxt : path) {
            if (nxt == u) {
                cycle = true;
            } 

            if (cycle) {
                out[nxt] = nxt; 
            } else {
                out[nxt] = u;
            }
        } 

    } else if (color[u] == 2) {
        for (int nxt : path) {
            out[nxt] = out[u];
        }
    } else {
        dfs(u, path);
    }
    color[v] = 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    fill(color, color+n+1, 0);
    fill(p, p+n+1, 0);
    fill(out, out+n+1, 0);

    for (int  i = 1; i <= n; i++) {
        cin >> p[i];
    }

    for (int i = 1; i <= n; i++) {
        if (!color[i]) {
            vector<int> path;
            dfs(i, path);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << out[i] << " ";
    }
    cout << endl;
    
    return 0;
}