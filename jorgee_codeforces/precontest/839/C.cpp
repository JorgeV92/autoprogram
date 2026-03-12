#include <iostream>
#include <vector>
#include <iomanip>


using namespace std;

constexpr int MAXN = 100002;

vector<int> adj[MAXN];
int N;


double dfs(int v, int p) {
    double sum = 0;
    for (auto u : adj[v]) {
        if (u != p) {
            sum += dfs(u, v) + 1;
        }
    }
    return sum ? sum / (adj[v].size() - (p != -1)) : 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << fixed << setprecision(7) << dfs(1,-1) << endl;

    return 0;
}