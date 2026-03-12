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
#include <cstdio>
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

const int N = 2007;
vector<int> adj[N];
int dist[N], has[N], ans;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        has[i] = 1;
        adj[i].clear();
    }
    for (int i = 0; i < k; i++) {
        int u; cin >> u;
        has[u] = 0;
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int Q;
    cin >> Q;
    while (Q--) {
        int s,t;
        cin >> s >> t;
        ans = -1;
        memset(dist, 0x3f, sizeof(dist));
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        dist[s] = has[s];
        pq.push({dist[s], s});
        while (!pq.empty()) {
            auto [d_v, v] = pq.top();
            pq.pop();
            if (d_v != dist[v]) continue;
            if (v == t) {
                ans = d_v;
                break;
            } 
            for (auto& u : adj[v]) {
                if (dist[v] + has[u] < dist[u]) {
                    dist[u] = dist[v] + has[u];
                    pq.push({dist[u], u});
                }
            }
        }
        cout << ans << '\n';
    }
}

void solve2() {
    vector<int> g[N];
    int d[N], A[N];
    int res{};
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i <= n; i++) {
        g[i].clear();
        A[i] = 1;
    }
    for (int i = 0; i < k; i++) {
        int u; cin >> u;
        A[u] = 0;
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int q;
    cin >> q;
    while (q--) {
        int s, t;
        cin >> s >> t;
        memset(d, 0x3f, sizeof(d));
        res = -1;
        deque<int> dq;
        d[s] = A[s];
        dq.push_back(s);
        while (!dq.empty()) {
            int v = dq.front();
            dq.pop_front();
            if (v == t) {
                res = d[v];
                break;
            }
            for (auto u : g[v]) {
                int w = A[u];
                if (d[v] + w < d[u]) {
                    d[u] = d[v] + w;
                    if (w == 0) dq.push_front(u);
                    else dq.push_back(u);
                }
            }
        }
        cout << res << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;
    while (tt--) {
        solve2();
    }
    return 0;
}