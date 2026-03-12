#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define ll long long 
#define pii pair<int,int>

const int INF = 1e9 + 7;

vector<vetor<pii>> adj;

ll dijkstra(int s, vector<int>& d, vector<int> apples, int k) {
    d[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, s});
    ll min_cost = INF;
    while (!pq.empty()) {
        auto [d_v, v] = pq.top();
        pq.pop();
        if (d_v != d[v]) continue;
    
        min_cost = min(min_cost, (ll)apples[v] + (ll)(k+1) * d_v);
        for (auto& edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) { 
                d[to] = d[v] + len;
                pq.push({d[to], to});
            }
        }
    }
    return min_cost;
}

int main() {

    int n, k;
    cin >> n >> k;
    
    vector<int> apples(n);
    for (int& a : apples) {
        cin >> a;
    }

    adj.assign(n, {});

    for (int i = 0; i < n; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        a--; b--;
        adj[u].push_back({v, w});
        adj[u].push_back({u, w});
    }

    vector<ll> ans;
    // We do N class to Dijkstra in total O(N * (M+N)LogN)
    for (int i = 0; i < n; i++) {
        vector<int> d(n, INF);
        ans.push_back(dijkstra(i, d, apples, k));
    }

    return 0;
}
