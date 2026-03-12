#include <iostream>
#include <vector>

using namespace std;

class Tree {
public:
    Tree(const vector<int>* _adj, int size) 
        : adj(_adj), log2dist(ceil(log2(size))), par(size),
        pow2ends(size, vector<int>(log2dist+1)), depth(size) {

        par[root] = -1;
        depth[root] = 0;
        dfs(root, root);

        for (int v = 0; v < size; v++) {
            pow2ends[v][0] = par[v];
        }

        for (int p = 1; p <= log2dist; p++) {
            for (int v = 0; v < size; v++) {
                int halfway = pow2ends[v][p-1];
                pow2ends[v][p] = (halfway == -1) ? -1 : pow2ends[halfway][p-1];
            }
        }
    }

    int kth_parent(int n, int k) {
        if (k >= par.size()) return -1;
        int at = n;
        for (int pow = 0; pow <= log2dist; pow++) {
            if ((k & (1 << pow)) != 0) {
                at = pow2ends[at][pow];
                if (at == -1) 
                    break;
            }
        }
        return at;
    }

    int lca(int n1, int n2) {
        if (depth[n1] < depth[n2]) 
            swap(n1, n2);
        n1 = kth_parent(n1, depth[n1] - depth[n2]);
        if (n1 == n2) 
            return n1;
        for (int i = log2dist; i >= 0; i--) {
            if (pow2ends[n1][i] != pow2ends[n2][i]) {
                n1 = pow2ends[n1][i];
                n2 = pow2ends[n2][i];
            }
        }
        return pow2ends[n1][0];
    }

    int dist(int n1, int n2) {
        return depth[n1] + depth[n2] - 2 * depth[lca(n1, n2)];
    }

private:
    const int root = 0;
    const vector<int>* adj;
    const int log2dist;
    vector<int> par;
    vector<vector<int>> pow2ends;
    vector<int> depth;

    void dfs(int at, int prev) {
        par[at] = prev;
        depth[at] = depth[prev] + 1;
        for (auto to : adj[at]) {
            if (to != prev) 
                dfs(to, at);
        }
    }
};

class Solution {
public:
    int dp[100000][27];
    vector<int> g[100000];
    int height[100000];
    vector<int> res;
    vector<pair<int,int>> gw[100000];

    void dfs(int node, int fa) {
        for (auto& c : gw[node]) {
            int child = c.first;
            int wt = c.second;

            if (child != fa) {
                height[child] = height[node] + 1;
                for (int j = 1; j <= 26; j++) {
                    dp[child][j] = dp[node][j];
                }
                dp[child][wt]++;
                dfs(child, node);
            } 
        }
    }
    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {     
        for (auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            g[u].push_back(v);
            g[v].push_back(u);
            gw[u].push_back({v, w});
            gw[v].push_back({u, w});
        }
        Tree tree(g, n);
        dfs(0, -1);
        
        for (auto& qq : queries) {
            int ai = qq[0], bi = qq[1];
            int lca = tree.lca(ai, bi);
            int total = height[ai] + height[bi] - 2 * (height[lca]);
            int maxi = 0;
            for (int j = 1;  j <= 26; j++) {
                int freq = dp[ai][j] + dp[bi][j] - 2*(dp[lca][j]);
                maxi = max(maxi, freq);
            }
            res.push_back(total - maxi);
        }
        return res;
    }
};


class SSolution {
public:
    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) { 
        int m = 32 - __builtin_clz(n);
        vector<pair<int,int>> g[n];
        int f[n][m];
        int p[n];
        int dp[n][26];
        int depth[n];
        memset(f, 0, sizeof(f));
        memset(dp, 0, sizeof(dp));
        memset(depth, 0, sizeof(depth));
        memset(p, 0, sizeof(p));
        for (auto& e : edges) {
            int u = e[0], v = e[1], w = e[2] - 1;
            g[u].push_back({v, w});
            g[v].push_back({u, w});
        }
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            f[i][0] = p[i];
            for (int j = 1; j < m; j++) {
                f[i][j] = f[f[i][j-1]][j-1];
            }
            for (auto& [j, w] : g[i]) {
                if (j != p[i]) {
                    p[j]= i;
                    memcpy(dp[j], dp[i], sizeof(dp[i]));
                    dp[j][w]++;
                    depth[j] = depth[i] + 1;
                    q.push(j);
                }
            }
        }
        vector<int> ans;
        for (auto& qq : queries) {
            int u = qq[0], v = qq[1];
            int x = u, y = v;
            if (depth[x] < depth[y]) 
                swap(x, y);
            for (int j = m-1; ~j; j--) {
                if (depth[x] - depth[y] >= (1 << j)) {
                    x = f[x][j];
                }
            }
            for (int j = m-1; ~j; j--) {
                if (f[x][j] != f[y][j]) {
                    x = f[x][j], y = f[y][j];
                }
            }
            if (x != y) 
                x = p[x];
            int mx = 0;
            for (int j = 1; j <= 26; j++) {
                mx = max(mx, dp[u][j] + dp[v][j] - 2*(dp[x][j]));
            }
            ans.push_back(depth[u] + depth[v] - 2 * depth[x] - mx);
        }
        return ans;
    }
};


class TSolution {
    int n, l;
    int timer;
    vector<vector<pair<int,int>>> adj;     // (neighbor, weight in [0..25])
    vector<int> tin, tout, depth;
    vector<vector<int>> up;               // up[v][i] = 2^i ancestor
    vector<array<int,26>> cnt;            // prefix counts from root

    void dfs(int v, int p) {
        tin[v] = ++timer;
        up[v][0] = p;
        for (int i = 1; i <= l; ++i) {
            up[v][i] = up[ up[v][i-1] ][i-1];
        }

        for (auto [u, w] : adj[v]) {
            if (u == p) continue;
            depth[u] = depth[v] + 1;
            cnt[u] = cnt[v];
            cnt[u][w]++;                  // add edge color on path to child
            dfs(u, v);
        }

        tout[v] = ++timer;
    }

    bool is_ancestor(int u, int v) const {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }

    int lca(int u, int v) const {
        if (is_ancestor(u, v)) return u;
        if (is_ancestor(v, u)) return v;
        for (int i = l; i >= 0; --i) {
            int uu = up[u][i];
            if (!is_ancestor(uu, v)) u = uu;
        }
        return up[u][0];
    }

    void preprocess(int root) {
        timer = 0;
        // l = ceil(log2(n)) is also fine; this bit-length works well:
        l = 32 - __builtin_clz(n);        // assumes n > 0
        tin.assign(n, 0);
        tout.assign(n, 0);
        depth.assign(n, 0);
        up.assign(n, vector<int>(l + 1, 0));
        cnt.assign(n, array<int,26>{});
        for (int i = 0; i < n; ++i) cnt[i].fill(0);

        dfs(root, root);
    }

public:
    vector<int> minOperationsQueries(int n_, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        n = n_;
        adj.assign(n, {});

        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2] - 1; // map 1..26 -> 0..25
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        preprocess(0);

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto &qq : queries) {
            int u = qq[0], v = qq[1];
            int a = lca(u, v);

            int dist = depth[u] + depth[v] - 2 * depth[a];

            int mx = 0;
            for (int c = 0; c < 26; ++c) {
                int freq = cnt[u][c] + cnt[v][c] - 2 * cnt[a][c];
                mx = max(mx, freq);
            }

            ans.push_back(dist - mx);
        }

        return ans;
    }
};