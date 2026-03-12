#include <iostream>
#include <vector>
#include <queue>

const int maxn = 500006;
std::vector<int> g[maxn];

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    std::vector<int> side(n, -1);
    std::vector<int> part[2];
    bool is_bipartite = true;
    std::queue<int> q;
    for (int st = 0; st < n; st++) {
        if (side[st] == -1) {
            q.push(st);
            side[st] = 0;
            part[0].push_back(st);
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                for (int u : g[v]) {
                    if (side[u] == -1) {
                        side[u] = side[v] ^ 1;
                        part[side[u]].push_back(u)
                        q.push(u);
                    } else {
                        is_bipartite &= side[u] != side[v];
                    }
                }
            }
        }
    }

    if (is_bipartite) {
        std::cout << (int)part[0].size() << "\n";
        for (int x : part[0]) std::cout << x + 1 << ' ';
        std::cout << "\n";

        std::cout << (int)part[1].size() << "\n";
        for (int x : part[1]) std::cout << x + 1 << " ";
        std::cout << "\n";
    } else {
        std::cout << "-1\n";
    }

    return 0;   
}