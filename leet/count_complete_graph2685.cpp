#include <iostream>
#include <vector>

using namespace std;

struct DSU {
    vector<int> e,edg,nds; void init(int N) {
        e = vector<int>(N, -1);
        edg = vector<int>(N, 0);
        nds = vector<int>(N, 1);        
    }
    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
    bool sameSet(int x, int y) { return get(x) == get(y); }
    int size(int x) { return -e[get(x)]; }
    bool unite(int x, int y) {
        x = get(x); y = get(y);
        if (x == y) {
            edg[x]++;
            return false;
        }
        if (e[x] > e[y]) swap(x, y);
        e[x] += e[y];
        e[y] = x;
        nds[x] += nds[y];
        edg[x] += edg[y]+1;
        return true;
    }
};

vector<vector<int>> adj;

int nodes_count;
int edges_count;

void dfs(int u, vector<bool>& vis) {
    vis[u] = true;
    nodes_count++;
    edges_count += adj[u].size();
    for (int v : adj[u] ) {
        if (!vis[v]) {
            dfs(v, vis);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;  
    cin >> n >> m;

    adj = vector<vector<int>>(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    DSU D;
    D.init(n);

    for (int i = 0; i < n; i++) {
        for (int j: adj[i]) {
            if (i < j)
                D.unite(i, j);
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (i == D.get(i)) {
            int v = D.nds[i];
            int e = D.edg[i];

            if (e == v*(v-1)/2) {
                count++;
            }
        }
    }

    cout << count << endl;

    auto dfs_solution = [&]() {
        vector<bool> vis(n);
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                nodes_count = 0;
                edges_count = 0;
                dfs(i, vis);

                if (edges_count == nodes_count * (nodes_count -1)) {
                    count++;
                }
            }

            
        }
        cout << count << endl;
    };
    
    return 0;
}

/*
Test input sample 1:
6 4
0 1
0 2
1 2
3 4
output : 3

Test input sample 2;
6 5
0 1
0 2
1 2
3 4
3 5
output : 1
*/