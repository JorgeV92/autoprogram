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

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return false;}
template<class T> inline bool chmin(T& a, T b) { if ( a > b) { a = b; return 1;} return false;}

using ll = long long;
using pii = pair<int,int>;

const int INF = 1e9;

vector<vector<pii>> adj;

void dijkstra(int s, int t, vector<int>& d) {
    int n = adj.size();
    d.assign(n,INF);
    set<pii> h;
    h.insert({0,s});
    d[s] = 0;
    while (!h.empty()) {
        int v = h.begin()->second;
        h.erase(h.begin());
        for (auto& edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;
            if (d[v] + len < d[to]) {
                h.erase({d[to], to});
                d[to] = d[v] + len;
                h.insert({d[to], to});
            }
        }
    }

    if (d[t] != INF) {
        OUT(d[t]);
    } else {
        OUT(-1);
    }

}   

void solve() {
    int n; 
    cin >> n;
    unordered_map<string,int> citiesToIdx;
    adj = vector<vector<pii>>(n+1);
    FORE(i,1,n) {
        string a;
        cin >> a;
        citiesToIdx[a] = i;
        int k;
        cin >> k;
        FOR(j,0,k) {
            int b, w;
            cin >> b >> w;
            adj[i].push_back({b, w});
        }
    }

    int r;
    cin >> r;
    while (r--) {
        string a, b;
        cin >> a >> b;
        int ai = citiesToIdx[a];
        int bi = citiesToIdx[b];
        vector<int> d;
        dijkstra(ai, bi, d);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }


    return 0;
}