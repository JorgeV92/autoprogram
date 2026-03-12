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

struct DSU {
    vector<int> e; void init(int N) { e = vector<int>(N,-1);}
    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
    bool unite(int x, int y) {
        x = get(x), y= get(y); if (x == y) return false;
        if (e[x] > e[y]) swap(x, y);
        e[x] += e[y];
        e[y] = x;
        return true;
    }
};

const int N = 1e5 + 7;
pii a[N];
bool vis[N];
int p[N];

void solve() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) 
        p[i] = i;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i].first);
        a[i].second = i;
    }
    sort(a, a+ n);

    DSU D;
    D.init(n);
    for (int i = 0 ;i < n; i++) {
        D.unite(i, a[i].second);
    }

    map<int, vector<int>> groups;
    for (int i = 0; i < n; i++) {
        int r = D.get(i);
        groups[r].push_back(i);
    }
    printf("%d\n", (int)groups.size());
    for (auto const& [r, ind] : groups) {
        printf("%d", (int)ind.size());
        for (int i : ind) {
            printf(" %d", i + 1);
        }
        printf("\n");
    }
}

void solve2() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].fs;
        a[i].sc = i;
    }
    sort(a, a+n);
    for (int i = 0; i < n; i++) {
        p[i] = a[i].second;
    }
    vector<vector<int>> ans;
    for (int i = 0 ; i < n; i++) {
        if (vis[i]) continue;
        int x = i;
        vector<int> cycle;
        while (!vis[x]) {
            vis[x] = true;
            cycle.push_back(x);
            x = p[x];
        }
        ans.push_back(cycle);
    }
    int len = ans.size();
    cout << len << '\n';
    for (int i = 0; i < len; i++) {
        int cc = ans[i].size();
        cout << cc << " ";
        for (int j = 0; j < cc; j++) {
            cout << ans[i][j] + 1 << " ";
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}