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
using pli = pair<ll ,int>;

const ll INF = 1e18;
const int N = 100006;
vector<pii> adj[N];
int p[N];
ll d[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    FORE(i,0,n) {
        adj[i].clear();
    }

    FOR(i,0,m) {
        int a, b;
        ll w;
        cin >> a >> b >> w;
        adj[a].pb({b, w});
        adj[b].pb({a, w});
    }

    auto dijkstra = [&](int s) {
        FORE(i,1,n) {
            d[i] = INF; p[i] = -1;
        }
        d[s] = 0;
        priority_queue<pli, vector<pli>, greater<pli>> h;
        h.push({0, s});
        while (!h.empty()) {
            auto [d_v, v] = h.top();
            h.pop();
            if (d[v] != d_v) continue;
            for (auto& edge : adj[v]) {
                int to = edge.fs;
                int len = edge.sc;
                if (d[v] + len < d[to]) {
                    d[to] = d[v] + len;
                    h.push({d[to], to});
                    p[to] = v;
                }
            }
        }
    };

    auto restore_path = [&](int s, int t) {
        vector<int> path;
        for (int v = t; v != s; v = p[v]) {
            path.push_back(v);
        }
        path.push_back(s);
        reverse(all(path));
        return path;
    };

    dijkstra(1);

    if (d[n] == INF) {
        OUT(-1);
    } else {
        vector<int> path = restore_path(1, n);
        FOR(i,0,path.size()) {
            cout << path[i] << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}

/*
5 6 
1 2 2
2 5 5 
2 3 4 
1 4 1 
4 3 3 
3 5 1
*/