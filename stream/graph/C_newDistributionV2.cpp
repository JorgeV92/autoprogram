#include <iostream>
#include <vector>
#include <queue>

const int maxn = 500006;
std::vector<int> e[maxn];
bool vis[maxn];
int ans[maxn];

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int k;
        std::cin >> k;
        std::vector<int> v(k);
        for (int j = 0; j < k; j++)  {
            std::cin >> v[j];
            v[j]--;
        }
        for (int j = 0; j + 1 < k; j++) {
            e[v[j]].push_back(v[j+1]);
            e[v[j+1]].push_back(v[j]);
        }
    }

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            std::vector<int> c;
            std::queue<int> q{{i}};
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                if (vis[v]) continue;
                vis[v] = true;
                c.push_back(v);
                for (auto u : e[v]) {
                    if (!vis[u]) {
                        q.push(u);
                    }
                }
            }
            for (auto cc : c) {
                ans[cc] = (int) c.size();
            }
        }
    }

    for (int i = 0; i < n; i++) {
        std::cout << ans[i] << ' ';
    }
    std::cout << "\n";
    return 0;
}