#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 10000;
const int LOG = 14;

struct LCA {
    // up[k][v] - is the 2^k-th ancestor of v
    int N; vector<vector<int>> up, adj; vector<int> depth;
    void init(int _N) { 
        N = _N; 
        int d = 1;
        while ((1<<d) < N) d++; // number of powers of 2 less than N
        up.assign(d, vector<int>(N));
        adj.resize(N);
        depth.resize(N);
    }
    
    void add_edge(int x, int y) { 
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    void gen(int R = 0) {
        up[0][R] = R; // parent of the root is itself
        dfs(R);
    }

    void dfs(int x=0) {
        // fill binary lifting table for node x
        for (int i = 1; i < up.size(); i++) {
            up[i][x] = up[i-1][up[i-1][x]];
        }
        for (int y : adj[x]) {
            if (y != up[0][x]) {
                up[0][y] = x;
                depth[y] = depth[x] + 1;
                dfs(y);
            }
        }
    }

    int jmp(int x, int d) {
        for (int i = up.size()-1; i >= 0; i--) {
            // If the i-th bit of d is set, move x up by 2^i using up[i][x]
            if ((d >> i) & 1) 
                x = up[i][x];
        }
        return x;
    }

    int lca(int x, int y) {
        if (depth[x] < depth[y])
            swap(x, y);
        int k = depth[x] - depth[y];
        x = jmp(x, k);
        if (x == y) return x;
        for (int i = up.size()-1; i >= 0; i--) {
            int X = up[i][x], Y = up[i][y];
            if (X != Y) {
                x = X, y = Y;
            }
        } 
        return up[0][x];
    }

    int dist(int x, int y) {
        return depth[x] + depth[y] - 2 * depth[lca(x, y)];
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    LCA tree;
    tree.init(n);

    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        while (t--) {
            int u;
            cin >> u;
            tree.add_edge(i, u);
        }
    }

    int Q;
    cin >> Q;

    for (int q = 0; q < Q; q++) {
        int u, v;
        cin >> u >> v;

        cout << tree.lca(u, v) << endl;

    }

    return 0;
}


// Leetcode 
/*
class TreeAncestor {
public:
    TreeAncestor(int n, vector<int> parent) {
        // Perform the pre-processing 
        LOG = 0;    
        while ((1 << LOG) <= n) { // how many powers of 2 do we have before we reach n
            LOG++;
        }
        this->up = vector<vector<int>>(n, vector<int>(LOG, -1));
        for (int v = 0; v < n; v++) {
            up[v][0] = parent[v];
        }

        for (int j = 1; j < LOG; j++) {
            for (int v = 0; v < n; v++) {
                if (up[v][j-1] == -1) continue;
                up[v][j] = up[ up[v][j-1] ][j-1];
            }
        }
    }

    int getKthAncestor(int node, int k) {
        for (int j = LOG-1; j >= 0; j--) {
            if ((k >> j) & 1) {
                node = up[node][j];
                if (node == -1) break;
            }
        }
        return node;
    }
    
private:
    vector<vector<int>> up; // up[v][j] is the 2^jth ancestor of v
    int LOG;
};

 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);


*/