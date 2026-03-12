#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string> // Added for indentation

using ll = long long;
// <res, resWithOperation, sum, max_depth>
using TT = std::tuple<ll,ll,ll,ll>;

const int maxn = 200000 + 5;
std::vector<int> tree[maxn];
ll V[maxn];
TT ans[maxn];

// Added 'indent' parameter to format the debug output nicely
TT dfs(int v, int fa, int indent = 0) {
    std::string prefix(indent * 4, ' '); // 4 spaces per depth level
    
    std::cerr << prefix << "========== Processing Node " << v + 1 << " ==========\n";
    std::cerr << prefix << "Initial Value: " << V[v] << "\n";

    TT curRes = std::make_tuple(0,0,V[v],0);
    ll maxDepth = 0;
    ll secondDepth = 0;
    ll used = 0;

    // Phase 1: DFS down to children and aggregate base metrics
    for (auto u : tree[v]) {
        if (u != fa) {
            std::cerr << prefix << "[Phase 1] Node " << v + 1 << " calling child " << u + 1 << "...\n";
            
            TT out = dfs(u, v, indent + 1);
            
            std::cerr << prefix << "[Phase 1] Node " << v + 1 << " received from child " << u + 1 << ":\n";
            std::cerr << prefix << "  -> BaseCost: " << std::get<0>(out) << ", MaxCost: " << std::get<1>(out) 
                      << ", Sum: " << std::get<2>(out) << ", MaxDepth: " << std::get<3>(out) << "\n";

            if (std::get<3>(out) + 1 >= maxDepth) {
                secondDepth = maxDepth;
                maxDepth = std::get<3>(out) + 1;
            } else if (std::get<3>(out) + 1 > secondDepth) {
                secondDepth = std::get<3>(out) + 1;
            }
            
            // max profit if the operation is used purely inside the child's subtree
            ll child_profit = std::get<1>(out) - std::get<0>(out);
            used = std::max(used, child_profit);
            std::cerr << prefix << "  -> Profit if operation used in child " << u + 1 << "'s branch: " << child_profit << "\n";

            std::get<0>(curRes) += std::get<0>(out) + std::get<2>(out);
            std::get<1>(curRes) += std::get<0>(out) + std::get<2>(out);
            std::get<2>(curRes) += std::get<2>(out);
        }
    }

    std::get<1>(curRes) += used;
    std::get<3>(curRes) = maxDepth;
    
    std::cerr << prefix << "[Intermediate] Node " << v + 1 << " Base metrics compiled.\n";
    std::cerr << prefix << "  -> BaseCost: " << std::get<0>(curRes) << ", MaxDepth: " << maxDepth 
              << ", SecondDepth: " << secondDepth << ", Max Profit from Below: " << used << "\n";

    // Phase 2: Evaluate doing the operation AT this current node
    for (auto u : tree[v]) {
        if (u != fa) {
            ll curr_ans = std::get<0>(ans[u]);
            ll curr_sum = std::get<2>(ans[u]);
            ll curr_depth = std::get<3>(ans[u]) + 1;

            ll max_depth_subtree = maxDepth;
            if (curr_depth == maxDepth) {
                max_depth_subtree = secondDepth;
            }

            ll cost_if_moved = std::get<0>(curRes) + max_depth_subtree * curr_sum;
            std::cerr << prefix << "[Phase 2] Node " << v + 1 << " testing cutting branch " << u + 1 << "\n";
            std::cerr << prefix << "  -> Moving branch " << u + 1 << " (weight: " << curr_sum 
                      << ") down by " << max_depth_subtree << " levels yields cost: " << cost_if_moved << "\n";

            std::get<1>(curRes) = std::max(std::get<1>(curRes), cost_if_moved);
        }
    }

    ans[v] = curRes;
    
    std::cerr << prefix << "<<< Final Answer for Node " << v + 1 << " >>>\n";
    std::cerr << prefix << "  -> [BaseCost=" << std::get<0>(curRes) << ", MaxCost=" << std::get<1>(curRes) 
              << ", Sum=" << std::get<2>(curRes) << ", MaxDepth=" << std::get<3>(curRes) << "]\n\n";
              
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
    
    std::cerr << "\n--- STARTING DFS TRACE ---\n\n";
    dfs(0, -1);
    std::cerr << "--- DFS FINISHED ---\n\n";

    // Standard output prints just the answers
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