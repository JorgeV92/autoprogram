#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using ll = long long;
// <res, resWithOperation, sum, max_depth>
using TT = std::tuple<ll,ll,ll,ll>;

const int maxn = 200000 + 5;
std::vector<int> tree[maxn];
ll V[maxn];
TT ans[maxn];

TT dfs(int v, int fa) {
    TT curRes = std::make_tuple(0,0,V[v],0);
    ll maxDepth = 0;
    ll secondDepth = 0;
    ll used = 0;

    for (auto u : tree[v]) {
        if (u != fa) {
            TT out = dfs(u, v);
            if (std::get<3>(out) + 1 >= maxDepth) {
                secondDepth = maxDepth;
                maxDepth = std::get<3>(out) + 1;
            } else if (std::get<3>(out) + 1 > secondDepth) {
                secondDepth = std::get<3>(out) + 1;
            }
            used = std::max(used, std::get<1>(out) - std::get<0>(out));

            std::get<0>(curRes) += std::get<0>(out) + std::get<2>(out);
            std::get<1>(curRes) += std::get<0>(out) + std::get<2>(out);
            std::get<2>(curRes) += std::get<2>(out);
        }
    }

    std::get<1>(curRes) += used;
    std::get<3>(curRes) = maxDepth;

    for (auto u : tree[v]) {
        if (u != fa) {
            ll curr_ans = std::get<0>(ans[u]);
            ll curr_sum = std::get<2>(ans[u]);
            ll curr_depth = std::get<3>(ans[u]) + 1;

            ll max_depth_subtree = maxDepth;
            if (curr_depth == maxDepth) {
                max_depth_subtree = secondDepth;
            }

            std::get<1>(curRes) = std::max(std::get<1>(curRes), std::get<0>(curRes) + max_depth_subtree * curr_sum);
        }
    }

    ans[v] = curRes;
    return curRes;
} 

void run() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        tree[i].clear();
        ans[i] = {};
        V[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        std::cin >> V[i];
    }
    for (int i = 0; i < n-1; i++) {
        int u, v;
        std::cin >> u >> v;
        u--; v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(0, -1);

    for (int i = 0; i < n; i++) {
        std::cout << std::get<1>(ans[i]) << " ";
    }
    std::cout << '\n';

}

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    int tt;
    std::cin >> tt;
    while (tt--) {
        run();
    }
    return 0;
}