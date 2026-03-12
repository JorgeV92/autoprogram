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

const int N = 2e5 + 12;
int a[N], b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    auto one = [&]() {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int j = 1; j <= n; j++) cin >> b[j];
        sort(a+1,a+n+1); reverse(a+1,a+n+1);
        int h = 0, sum =0;
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            while (h < n && sum + b[h+1] <= i) h++, sum += b[h];
            ans = max(ans, a[i]* 1ll * h);
        }
        cout << ans << '\n';
    };
    auto two= [&]() {
        int n;
        cin >> n;
        vector<ll> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int j = 0; j < n; j++) cin >> b[j];
        sort(a.begin(), a.end(), greater<ll>());
        vector<ll> pref(n+1,0);
        for (int i = 1; i < n; i++) {
            pref[i] = pref[i-1] + b[i-1];
        }
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ll x = a[i], cnt = i+1;
            ll k = upper_bound(pref.begin(), pref.end(), cnt) - pref.begin() - 1;
            ans = max(ans, x*k);
        }
        cout << ans << '\n';
    };
    while (tt--) {
        // one();
        two();
    }
    return 0;
}