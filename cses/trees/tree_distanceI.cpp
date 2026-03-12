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

const int N = 200006;
vector<int> adj[N];
int dist[2][N];

int dfs(int u, int p, int d, int i) {
    dist[i][u] = d;
    int opt = -1;
    for (auto v: adj[u]) {
        if (v == p) continue;
        int x = dfs(v, u, d+1, i);
        if (opt == -1 || dist[i][x] > dist[i][opt]) opt = x;
    }
    return opt == -1 ? u : opt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    FOR(i,0,n-1) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int nodeA = dfs(1,0,0,0);
    int nodeB = dfs(nodeA,0,0,0);
    dfs(nodeB,0,0,1);
    FORE(i,1,n) {
        cout << max(dist[0][i], dist[1][i]) << " \n"[i==n];
    }

    return 0;
}