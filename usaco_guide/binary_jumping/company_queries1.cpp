#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


struct LCA {
    int N; vector<vector<int>> up, adj; vector<int> depth;
    void init(int _N) {
        N = _N;
        int d = 1;
        while ((1 << d) < N) d++;
        up.assign(d, vector<int>(N, -1)); // up[k][v] is the 2^k-th ancestor of v
        adj.resize(N);
        depth.resize(N);
    }
    void add_edge(int x, int y) {
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    void gen(int R=0) {
        dfs(R, -1);     
    }
    void dfs(int x, int p) {
        up[0][x] = p;
        for (int i = 1; i < (int)up.size(); i++) {
            if (up[i-1][x] != -1) {
                up[i][x] = up[i-1][ up[i-1][x] ];
            } else {
                up[i][x] = -1;
            }
        }
        for (int y : adj[x]) {
            if (y == p) continue;
            up[0][y] = x;
            depth[y] = depth[x] + 1;
            dfs(y, x);
        }
    }
    int jmp(int x, int d) {
        for (int i = up.size() -1; i >= 0; i--) {
            if ((d >> i) & 1) {
                x = up[i][x];
                if (x == -1) 
                    break;
            }
        }
        return x;
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    LCA tree;
    tree.init(N+1);

    for (int i = 2; i <= N; i++) {
        int a;
        cin >> a;
        tree.add_edge(a, i);
    }

    tree.gen(1);

    while (Q--) {
        int a, k;
        cin >> a >> k;
        cout << tree.jmp(a, k) << endl;
    }

    return 0;
}