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
using pli = pair<ll,int>;

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
    FOR(i,0,m) {
        int a, b, w;
        cin >> a >> b >> w;
        a--; b--;
        adj[a].pb(mp(b,w));
        adj[b].pb(mp(a,w));
    }
    FOR(i,0,n) {
        d[i] = INF; p[i] = -1;
    }

    priority_queue<pli, vector<pli>, greater<pli>> h;
    h.push(mp(0,0));
    d[0] = 0;
    while (!h.empty()) {
        auto [d_v, v] = h.top(); 
        h.pop();
        if (d_v != d[v]) continue;
        for (auto& edge : adj[v]) {
            int to = edge.fs;
            int len = edge.sc;
            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                h.push(mp(d[to], to));
                p[to] = v;
            } 
        }
    }

    if (d[n-1] == INF) {
        OUT(-1);
    } else {
        vector<int> path;
        for (int v = n-1; v != 0; v = p[v]) path.push_back(v);
        path.push_back(0);
        reverse(all(path));
        FOR(i,0,path.size()) {
            cout << path[i]+1 << ' ';
        }
        cout << '\n';
    }

    return 0;
}