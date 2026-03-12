#include <iostream>
#include <vector>
#include <cstdint>
#include <map>

using pi = std::pair<int,int>;

const int maxn = 300005;
int n, vis[maxn], dp[maxn];
int id;
std::vector<pi> ans;
std::map<int, std::vector<int>> cache;

std::vector<int> ask(int d) {
    if (cache.count(d)) return cache[d];
    std::cout << "? " << d << '\n';
    int x;
    std::cin >> x;
    std::vector<int> p(x);
    for (auto& a : p) std::cin >> a;
    return cache[d] = p;
}

void dfs(int u) {
    if (vis[u]) {
        id += dp[u] - 1;
        return;
    }
    vis[u] = 1;
    while (true) {
        id += 1;
        auto x = ask(id);
        if ((u == 0 && x.size() >= 1) || (u != 0 && x.size() >= 2 && x.end()[-2] == u)) {
            int v = x.end()[-1];
            dfs(v);
            if (u != 0) ans.push_back({u,v});
            dp[u] += dp[v]; 
        } else {
            id -= 1;
            return;
        }
    }
}

void solve() {
    cache.clear();
    ans.clear();
    std::cin >> n;
    for (int i = 0; i <= n; i++) {
        vis[i] = 0;
        dp[i] = 1;
    }
    id = 0;
    dfs(0);
    std::cout << "! " << ans.size() << '\n';
    for (auto& [u, v] : ans) 
        std::cout << u << ' ' << v << '\n';
}

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    int tt;
    std::cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}