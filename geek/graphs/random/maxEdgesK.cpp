#include <iostream>
#include <vector>

using namespace std;

class Graph {
public:
    Graph(int n) : N{n} {
        g = vector<vector<int>>(N+1);
    } 

    void add_edge(int a, int b) {
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int countRemovedEdges(int n, int m, int k) {
        vector<bool> vis(n+1);
        
        auto dfs = [&](auto&& dfs, int v) -> void {
            vis[v] = true;
            for (auto u : g[v])
                if (!vis[u])
                    dfs(dfs, u);
        };

        int c = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i])  {
                dfs(dfs,i);
                c++;
            }
        }

        if (c <= k) {
            return m -(n-k);
        } else {
            return -1;
        }
    }
    
private:
    vector<vector<int>> g;
    int N{};
    int M{};
};

struct DSU {
    int cc; vector<int> e; void init(int N) { e = vector<int>(N,-1); cc = N; }
    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
    bool unite(int x, int y) {
        x = get(x), y = get(y); if (x == y) return false;
        e[x] += e[y];
        e[y] = x;
        cc--;
        return true;
    }
};



int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n = 4, m = 3, k = 2;
    Graph graph(n);
    graph.add_edge(1, 2);
    graph.add_edge(2, 3);
    graph.add_edge(3, 4);
    cout << graph.countRemovedEdges(n, m, k) << "\n";


    DSU D;
    D.init(n+1);
    D.unite(1, 2);
    D.unite(2, 3);
    D.unite(3, 4);
    if (D.cc-1 <= k) {
        cout << m - (n - k) << '\n';
    } else {
        cout << -1 << '\n';
    }

    return 0;
}

/*
    Topics:
        Encapsulation, inheritance, polymorphism & abstraction
*/