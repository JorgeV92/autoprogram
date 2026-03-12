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

ll n, ax, ay, bx, by;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> ax >> ay >> bx >> by;
        vector<ll> x(n+5), y(n+5);
        vector<ll> dp[2];

        dp[0] = dp[1] = vector<ll>(n+5, 0);
        map<ll, ll> mx, mn;

        mn[ax] = mx[ax] = ay;
        mn[bx] = mx[bx] = by;

        for (int i = 0; i < n; i++) cin >> x[i];
        for (int i = 0; i < n; i++) cin >> y[i];

        for (int i = 0; i < n; i++) {
            mx[x[i]] = max(mx[x[i]], y[i]);

            if (!mn.count(x[i])) mn[x[i]] = y[i];
            else mn[x[i]] = min(mn[x[i]], y[i]);
        }
        ll lst = ax, cnt = 0;

        for (auto& i : mx) {
            if (i.first == ax) {
                dp[0][0] = dp[1][0] = 0;
                continue;
            }
            ll need = (i.first - lst) + (mx[i.first] - mn[i.first]);
            cnt++;
            // dp[0] bottom
            // dp[1] top
            dp[0][cnt] = min(
                dp[0][cnt-1] + llabs(mx[i.first] - mn[lst]), 
                dp[1][cnt-1] + llabs(mx[i.first] - mx[lst])
            ) + need;

            dp[1][cnt] = min(
                dp[0][cnt-1] + llabs(mn[i.first] - mn[lst]), 
                dp[1][cnt-1] + llabs(mn[i.first] - mx[lst]) 
            ) + need;

            lst = i.first;
        }

        cout << dp[0][cnt] << '\n';
    }
    return 0;
}