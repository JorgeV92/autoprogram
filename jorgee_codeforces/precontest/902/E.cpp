#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> nxt(n);
    set<int> unvisited;
    for (int i = 0; i < n; i++) {
        unvisited.insert(i);
    }
    vector<set<int>> e(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        e[u].insert(v);
        e[v].insert(u);
    }
    vector<int> sol;
    
    auto bfs = [&](int s) {
        queue<int> q;
        q.push(s);
        unvisited.erase(s);
        int t = 0;
        while (!q.empty()) {
            int u = q.front(); 
            q.pop();
            ++t;
            auto it = unvisited.begin();
            while (it != unvisited.end()) {
                int v = *it;
                auto nxt = next(it);
                if (!e[u].count(v)) {
                    q.push(v);
                    unvisited.erase(it);
                }
                it = nxt;
            }
        }
        sol.push_back(t);
    };

    for (int i = 0; i < n; i++) {
        if (unvisited.count(i))
            bfs(i);
    }
    sort(sol.begin(), sol.end());
    cout << sol.size() << endl;
    for (int i = 0; i < sol.size(); i++) 
        cout << sol[i] << " \n"[i+1 == sol.size()];

    return 0;
}