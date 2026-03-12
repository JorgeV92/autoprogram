#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

vector<vector<pair<int,int>>> adj;
const int INF = 1000000000;


int dijkstra(int src, int dst, vector<int>& d) {
    using pii = pair<int,int>;
    const int n = adj.size();
        
    d[src] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        int v = pq.top().second;
        int d_v = pq.top().first;
        pq.pop();
        if (d_v != d[v]) continue;
        
        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;
            
            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                pq.push({d[to], to}); 
            } 
        }
    }


    if (d[dst] >=  INF) return -1;
    return d[dst];
    
}

void print_adj() {
    const int n = adj.size();
    for (int i = 1; i < n; i++) {
        for (const auto& p : adj[i]) {
            cout << "node i: " << i << " neighbors " << p.first << " with weight " << p.second << endl;
        }
    } 
}

int main() {
    
    int s, n;
    cin >> s >> n;

    unordered_map<string, vector<pair<int,int>>> cityToNeigh; 
    unordered_map<string, int> cityToIdx;

    for (int i = 0; i < n; i++) {
        string city;
        cin >> city;
        cityToIdx[city] = i+1;
        int p;
        cin >> p;
            
        for (int j = 0; j < p; j++)  {   
            int u, w;   
            cin >> u >> w;
            cityToNeigh[city].push_back({u,w});
        }
    }


    int r;
    cin >> r;
    // O (N + P) where P is the total neighbors 
    // which are edges build in the graph 
    adj = vector<vector<pair<int,int>>>(n+1);
    for (const auto& [cty, neigh] : cityToNeigh) {
        int idx_city = cityToIdx[cty];

        for (const auto& [v, w] : neigh) {
            adj[idx_city].push_back({v, w});
        }
    }

    // print_adj();    
    
    
    vector<int> ans;
    
    for (int i = 0; i < r; i++) {
        string src, dst;
        cin >> src >> dst;

        int start = cityToIdx[src];
        int end = cityToIdx[dst];
        
        vector<int> dist(n+1, INF);    
        // O(R * (N + P)logN)
        ans.push_back(dijkstra(start, end, dist));
    } 
        
    for (int x : ans) {
        cout << x << endl;
    }

    //total running time O(N+P + R * (N+P)logN) -> O((N+P)logN) 

    return 0;
}
