#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#include <string_view>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define OUT(x) cout << x << '\n'
#define all(x) (x).begin(), (x).end()
#define FOR(i,a,b) for(int i = (a); i < (b); i++) 
#define FORE(i,a,b) for(int i = (a); i <= (b); i++)
#define ROF(i,a,b) for(int i = (a); i >= (b); i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return false;}
template<class T> inline bool chmin(T& a, T b) { if ( a > b) { a = b; return 1;} return false;}

using ll = long long;
using pii = pair<int,int>;


vector<pii> adj[100005];
ll dist[2][100005];

int dfs(int u, int p, ll d, int i) {
    dist[i][u] = d;
    int opt = -1;
    for (auto& edge : adj[u]) {
        int v = edge.fs;
        ll w = edge.sc;
        if (v != p) {
            int x = dfs(v, u, d + w, i);
            if (opt == -1 || dist[i][x] > dist[i][opt]) opt = x;
        }
    }
    return opt == -1 ? u : opt;
}

void solve() {
    int n; 
    cin >> n;

    FORE(i,1,n) {
        adj[i].clear();
    }
    FOR(i,0,n-1) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u,w});
    }
    int nodeA = dfs(1,0,0,0);
    int nodeB = dfs(nodeA,0,0,0);
    dfs(nodeB,0,0,1);
    FORE(i,1,n) {
        cout << max(dist[0][i], dist[1][i]) << " \n"[i==n];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >>t;
    while (t--) {
        solve();
    }
    return 0;
}