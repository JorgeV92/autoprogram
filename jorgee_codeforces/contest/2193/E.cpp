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

void solve() {
    int n;
    cin >> n;
    vector<int> distinct;
    vector<bool> present(n+1,false);
    FOR(i,0,n) { 
        int x; cin >> x;
        if (!present[x]) {
            present[x] = true;
            distinct.pb(x);
        }
    }
    sort(all(distinct));
    vector<int> dist(n+1,-1);
    queue<int> q;

    for (int x : distinct) {
        dist[x] = 1;
        q.push(x);
    } 
    vector<int> multi;
    for (int x : distinct) {
        if ( x > 1) multi.pb(x);
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : multi) {
            ll nxt = (ll)u * v;
            if (nxt > n) break;
            if (dist[(int)nxt] == -1) {
                dist[(int)nxt] = dist[u] + 1;
                q.push((int)nxt);
            }
        }
    }
    FORE(i,1,n) {
        cout << dist[i] << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}