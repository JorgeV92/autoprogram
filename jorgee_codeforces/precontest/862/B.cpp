#include <iostream>
#include <vector>

using namespace std;
#define ll long long

constexpr int MAXN = 1e5 + 1;
vector<int> e[MAXN];
ll color[2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    auto dfs = [&](auto&& dfs, int v, int p, bool s) -> void {
        color[s]++;
        for (auto u : e[v]) {
            if (u == p) continue;
            dfs(dfs, u, v, !s);
        }
    };

    dfs(dfs, 0, -1, 0);
    cout << color[0] * color[1] - (n-1) << endl;

    return 0;
}