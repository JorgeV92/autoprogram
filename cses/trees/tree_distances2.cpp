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

vector<int> adj[200005];
ll dp[200005], ans[200005];
int n;

void dfs1(int node=1, int p = 0, ll depth = 0) {
    ans[1] += depth;
    dp[node] = 1;
    for (int x : adj[node]) {
        if (x != p) {
            dfs1(x, node, depth+1);
            dp[node] += dp[x];
        }
    }
}

void dfs2(int node=1, int p = 0) {
    for (int x : adj[node]) {
        if (x != p) {
            ans[x] = ans[node] + n - 2* dp[x];
            dfs2(x,node);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    FOR(i,0,n-1) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs1();
    dfs2();
    FORE(i,1,n) {
        cout << ans[i] << " ";
    }
    cout << '\n';

    return 0;
}
