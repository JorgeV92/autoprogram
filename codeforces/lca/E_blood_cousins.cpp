#include <iostream>
#include <vector>
#include <algorithm>

int n, q, dfn;
std::vector<std::vector<int>> e, queires;
std::vector<int> k, stk, in, height, depth, ans, f, parent;

void dfs1(int u) {
    stk.push_back(u);
    for (int i : queires[u]) {
        if (k[i] <= depth[u]) {
            ans[i] = stk[depth[u] - k[i]];
        } else {
            ans[i] = -1;
        }
    }
    height[u] = 1;
    for (auto& v : e[u]) {
        depth[v] = depth[u] + 1;
        dfs1(v);
        height[u] = std::max(height[u], height[v] + 1);
        if (height[v] > height[e[u][0]])
            std::swap(v, e[u][0]);
    }
    stk.pop_back();
}

void dfs2(int u) {
    in[u] = dfn++;
    f[in[u]] = 1;
    for (auto v : e[u]) {
        dfs2(v);
        if (v != e[u][0]) {
            for (int i = 0; i < height[v]; i++) {
                f[in[u] + i + 1] += f[in[v] + i];
            }
        }
    }
    for (int i : queires[u]) {
        ans[i] = f[in[u] + k[i]] - 1;
    }
}

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    
    std::cin >> n;
    e.resize(n);
    queires.resize(n);
    f.resize(n);
    in.resize(n);
    height.resize(n);
    depth.resize(n);
    stk.reserve(n);
    parent.resize(n);

    for (int i = 0; i < n; i++) {
        std::cin >> parent[i];
        --parent[i];
        if (parent[i] != -1) 
            e[parent[i]].push_back(i);
    }
    std::cin >> q;
    k.resize(q);
    ans.resize(q);
    for (int i = 0; i < q; i++) {
        int u;
        std:: cin >> u >> k[i];
        --u;
        queires[u].push_back(i);
    }
    for (int i = 0; i < n; i++) {
        if (parent[i] == -1)
            dfs1(i);
    }
    for (int i = 0; i < n; i++) {
        queires[i].clear();
    }
    for (int i = 0; i < q; i++) {
        if (ans[i] == -1) {
            ans[i] = 0;
        } else {
            queires[ans[i]].push_back(i);
        }
    }
    for (int i = 0; i < n; i++) {
        if (parent[i] == -1)
            dfs2(i);
    }
    for (int i = 0; i < q; i++) {
        std::cout << ans[i] << " ";
    }
    std::cout << "\n";
    return 0;
}