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
#include <iomanip>
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

typedef long double ld;
using ll = long long;
using pii = pair<int,int>;

const int maxn = 2e5 + 12, maxv = 1e6 + 15, mod = 1e9 + 7;

int n;
vector<int> g[maxn];
ld dfs(int v=0, int p=-1) {
    ld sum = 0;
    for (auto u : g[v]) {
        if (u != p) {
            sum += dfs(u, v) + 1;
        }
    }
    return sum ? sum / (g[v].size() - (p != -1)) : 0;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int v, u, i = 1; i < n; i++) {
        cin >> v >> u;
        v--; u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    cout << fixed << setprecision(7) << dfs() << '\n';

    return 0;
}