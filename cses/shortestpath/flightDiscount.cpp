#include <iostream>
#include <vector>
#include <queue>

using namespace std; 

using i64 = long long;
constexpr i64 INF = 1e18;
using pli = pair<i64, int>;
using pii = pair<int,int>;

struct Edge {
    int u, v, w;
};

vector<vector<pii>> adj1, adj2;
vector<Edge> e;
vector<i64> d1, d2;
int n, m;

void dijkstra(int s, vector<i64>& d, vector<vector<pii>>& g) {
    priority_queue<pli, vector<pli>, greater<pli>> h;
    h.push({0, s});
    d[s] = 0;
    while (!h.empty()) {
        auto [d_v, v] = h.top();
        h.pop();
        if (d_v != d[v]) continue;

        for (auto& edge : g[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                h.push({d[to], to});
            }
        }
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    adj1 = vector<vector<pii>>(n);
    adj2 = vector<vector<pii>>(n);
    e = vector<Edge>(m);
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        a--; b--;
        adj1[a].push_back({b, w});
        adj2[b].push_back({a, w});
        e[i] = {a, b, w};
    }
    d1.assign(n, INF);
    d2.assign(n, INF);
    dijkstra(0, d1, adj1);
    dijkstra(n-1, d2, adj2);


    i64 smll = INF;
    for (auto& ed : e) {
        int a = ed.u, b = ed.v, w = ed.w;
        smll = min(smll, d1[a] + d2[b] + w/2);
    } 
    cout << smll << endl;
    return 0;
}