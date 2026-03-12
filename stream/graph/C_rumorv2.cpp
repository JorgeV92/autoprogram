#include <iostream>
#include <vector>

using ll = long long;

const int maxn = 100006;
std::vector<int> e[maxn];
bool vis[maxn];
ll c[maxn];
ll n, m;

ll dfs(int v) {
    ll mn = c[v];
    vis[v] = true;
    for (auto u : e[v]) {
        if (!vis[u]) 
            mn = std::min(mn, dfs(u));
    }
    return mn;
}

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    std::cin >>n >> m;
    for (int i = 0; i < n; i++) {
        std::cin >> c[i];
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (!vis[i])
            ans += dfs(i);
    }
    std::cout << ans << '\n';
    return 0;
}