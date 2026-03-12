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
    ll n, x;
    cin >> n >> x;
    ll sum = 0;
    ll mx = -4e18;
    for (int i = 0; i < n; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        sum += (b-1) * a;
        ll roll = b*a-c;
        if (roll > mx) {
            mx = roll;
        }
    }
    if (sum >= x) {
        cout << 0 << '\n';
        return;
    } 
    if (mx <= 0) {
        cout << -1<< '\n';
        return;
    }
    ll need = x - sum;
    ll ans = (need + mx - 1) / mx;
    cout << ans << '\n';
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