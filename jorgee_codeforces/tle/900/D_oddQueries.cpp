#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#include <string_view>

using namespace std;

#define OUT(x) cout << x << '\n'
#define all(x) (x).begin(), (x).end()
#define FOR(i,a,b) for(int i = (a); i < (b); i++) 
#define FORE(i,a,b) for(int i = (a); i <= (b); i++)
#define ROF(i,a,b) for(int i = (a); i >= (b); i--)

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return false;}
template<class T> inline bool chmin(T& a, T b) { if ( a > b) { a = b; return 1;} return false;}

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<ll> a(n);
        ll total_sum = 0;
        FOR(i,0,n) {
            cin >> a[i];
            total_sum += a[i];
        }
        vector<ll> prefix(n+1);
        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i-1] + a[i-1];;
        }

        while (q--) {
            ll l, r, k;
            cin >> l >> r >> k;
            ll sum = prefix[r] - prefix[l-1];
            ll newSum = (r-l+1) * k;
            ll res = total_sum - sum + newSum;
            if (res % 2 == 1) {
                OUT("YES");
            }  else {
                OUT("NO");
            }
        }

    }

    return 0;
}