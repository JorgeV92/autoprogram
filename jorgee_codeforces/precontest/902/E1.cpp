#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    set<int> unvisited;
    for (int i = 0; i < n; i++) 
        unvisited.insert(i);
    vector<set<int>> e(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        e[u].insert(v);
        e[v].insert(u);
    }
    vector<int> sol;
    int cc =  0;
    auto dfs = [&](auto&& dfs, int u) -> void {
        cc++;
        vector<int> nodes;
        auto it = unvisited.begin();
        while (it != unvisited.end()) {
            int v = *it;
            auto nxt = next(it);
            if (!e[u].count(v)) {
                unvisited.erase(it);
                nodes.push_back(v);
            }
            it = nxt;
        }

        for (int v : nodes) {
            dfs(dfs, v);
        }
    };
    
    for (int i = 0; i < n; i++) {
        if (unvisited.count(i)) {
            unvisited.erase(i);
            cc = 0;
            dfs(dfs, i);
            sol.push_back(cc);
        }
    }
    sort(sol.begin(), sol.end());
    cout << sol.size() << endl;
    for (int i = 0; i < sol.size(); i++) 
        cout << sol[i] << " \n"[i+1 == sol.size()];

}