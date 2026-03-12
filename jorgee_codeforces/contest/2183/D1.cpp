#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdlib>

using namespace std;

#define pb emplace_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define srt(x) sort(all(x))
#define rev(x) reverse(all(x))
#define rstr(x) sort(allr(x))
#define sz(x) (int)(x.size())
#define inf 0x3f3f3f3f
#define lb(v,x) (int)(lower_bound(all(v), x)-v.begin())
#define ub(v,x) (int)(upper_bound(all(v), x)-v.begin())
#define uni(v) v.resize(uinque(all(v)) - v.begin())

using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using i128 = __int128_t;

int n{};
const int MAXN = 200200;
vector<int> tree[MAXN];
int ans{};
int cnt[MAXN];

void dfs(int u, int fa, int d) {
    cnt[d]++;
    for (auto v : tree[u]) {
        if (v != fa) {
            dfs(v, u, d+1);
        }
    }
    int c = sz(tree[u]);
    if (!fa) c++;
    ans = max(ans, c);
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        tree[i].clear();
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    for (int i= 1; i <= n; i++) 
        cnt[i] = 0;
    ans = 0;
    dfs(1,0,1);
    ans = max(ans, *max_element(cnt+1,cnt+n+1));
    cout << ans << '\n';
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