#include <iostream>
#include <vector>

using namespace std;

#define vi vector<int>

struct DSU {
    vi e; void init(int N) { e = vi(N,-1); }
    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
    bool sameSet(int x, int y) { return get(x)  == get(y); };
    int size(int x) { return -e[get(x)]; }
    bool unite(int x, int y) {
        x = get(x); y = get(y);
        if (x == y) return false;
        if (e[x] > e[y]) swap(x, y);
        e[x] += e[y];
        e[y] = x;
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> queries(n);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        a--;
        queries[n-i-1] = a;
    }

    DSU D;
    D.init(n);
    vector<bool> activated(n);
    vector<bool> ans(n);

    int c = 0;
    for (int i = 0; i < n; i++) {
        int u = queries[i];
        c++;
        activated[u] = true;
        for (int v : adj[u]) {
            if ((activated[u] && activated[v]) && (D.get(u) != D.get(v))) {
                D.unite(u, v);
                c--;
            }
        }

        ans[n-i-1] = c == 1;
    }

    for (int i = 0; i < ans.size(); i++) {
        if (ans[i]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}

