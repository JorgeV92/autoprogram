#include <iostream>
#include <vector>

const int maxn = 100005;
int N, M, ans;
std::vector<int> e[maxn];
bool cat[maxn];

void dfs(int u, int fa, int cnt) {
    if (cnt > M)
        return;
    bool is_leaf = 1;
    for (auto v : e[u]) {
        if (v == fa) 
            continue;
        is_leaf = 0;
        dfs(v, u, cat[v]?cnt+1:0);
    }
    ans += is_leaf;
}

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    std::cin >> N >> M;
    for (int i = 1; i <= N; i++) 
        std::cin >> cat[i];
    for (int i = 1; i < N; i++) {
        int u, v;
        std::cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0, cat[1]);
    std::cout << ans << '\n';
    return 0;
}