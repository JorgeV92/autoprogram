#include <iostream>
#include <set>
#include <vector>
#include <deque>

using namespace std;

enum { UPHILL = 0, DOWNHILL = 1};

using pii = pair<int,int>;

const int inf = 1e9;

vector<vector<pii>> adj;
int n, m;

// 0/1 BFS
int solve(int s, int t) {
    vector<vector<int>> dist(n ,vector<int>(2, inf));
    deque<pii> dq;
    if (s == t) return 0;

    for (auto& edge : adj[s]) {
        int to = edge.first;
        int dir = edge.second;

        if (dist[to][dir] > 0) {
            dist[to][dir] = 0;
            dq.push_front({to, dir});
        }
    }

    while (!dq.empty()) {
        auto [u, mode] = dq.front();
        dq.pop_front();

        for (auto& edge : adj[u]) {
            int to = edge.first;
            int dir = edge.second;

            int w = (dir == mode ? 0 : 1);

            if (dist[u][mode] + w < dist[to][dir]) {
                dist[to][dir] = dist[u][mode] + w;
                if (w == 0) {
                    dq.push_front({to, dir}); // cost 0
                } else {
                    dq.push_back({to, dir}); // cost 1
                }
            }
        }
    }

    return min(dist[t][UPHILL], dist[t][DOWNHILL]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    int s, t;
    adj = vector<vector<pii>>(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back({v, UPHILL});
        adj[v].push_back({u, DOWNHILL});
    }
    cin >> s >> t;
    s--; t--;
    
    cout << solve(s ,t) << endl;

    return 0;
}