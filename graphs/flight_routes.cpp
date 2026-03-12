#include <iostream>
#include <vector>
#include <queue>


using namespace std;


#define ll long long 

const int MX = 2e5 + 5;

vector<vector<pair<int,int>>> adj;

void dijkstra(int s, int t, int k) {
    priority_queue<ll> best[MX];
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

    best[s].push(0);
    pq.push({0, s});

    while (!pq.empty()) {
        ll v = pq.top().second;
        int d_v = pq.top().first;
        pq.pop();
        
        if (d_v > best[v].top())
            continue;
        
        for (auto& edge : adj[v]) {
            int to = edge.first;
            ll len = edge.second;
            
            if (best[to].size() < k) {
                best[to].push(d_v + len);
                pq.push({d_v + len, to});
            }  else if (d_v + len < best[to].top()) {
                best[to].pop();
                best[to].push(d_v + len);
                pq.push({d_v + len, to});
            }
        }
    }


    vector<ll> ans;
    while (!best[t].empty()) {
        ans.push_back(best[t].top());
        best[t].pop();   
    }
    reverse(ans.begin(), ans.end());
    for (ll x : ans) cout << x << " ";
    cout << endl;
}

vector<int> restore_path(int s, int t, vector<int>& p);


int main() {

    int n, m, k;
    cin >> n >> m >> k;

    adj.assign(n+1, {});

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    // O(mk log(mk))    
    dijkstra(1, n, k);
    
    return 0;
}
