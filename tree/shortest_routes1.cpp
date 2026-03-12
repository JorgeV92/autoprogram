#include <iostream>
#include <vector>

using namespace std;


const int MAX_N = 100001;
const int MAX_M = 200001;
const int INF = 1000000000;

vector<vector<pair<int,int>>> adj;
vector<int> d;
vector<int> p;

void dijkstra(int s) {
    int n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);
    vector<bool> u(n, false);

    d[s] = 0;
    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++) {
            if (!u[j] && (v == -1 || d[j] < d[v])) {
                v = j;
            }
        }
        
        if (d[v] == INF) break;
        u[v] = true;
        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;
                

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                // cout << "predecessor: " << v << " of " << to << endl;
                p[to] = v;
            }
        }
    }
}


int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    
    adj.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        a--; b--; 
        adj[a].push_back(make_pair(b, c));
    }        

    dijkstra(0);
        
    for (int v = 0; v < n; v++) {
        cout << d[v] << " ";         
    }
    cout << endl;

    return 0;
}
