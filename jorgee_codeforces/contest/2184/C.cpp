#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>

using namespace std;

#define OUT(x) cout << x << '\n';
#define all(x) (x).begin(), (x).end()
#define FOR(i,a,b) for(int i = (a); i < (b); i++) 
#define FORE(i,a,b) for(i = (a); i <= (b); i++)
#define ROF(i,a,b) for(int i = (a); i >= (b); i--)

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return false;}
template<class T> inline bool chmin(T& a, T b) { if ( a > b) { a = b; return 1;} return false;}

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >>t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        ll ans = 4e18;
        ll p = 1;
        for (ll d = 0; d <= 60; d++) {
            ll flo = n/p;
            ll cei = (n+p-1)/p;
            if (flo == k || cei == k)
                chmin(ans,d);
            if (flo == 0 && k > 1) break;
            p <<= 1;
        }
        if (ans > (ll)3e18) {
            OUT(-1);
        } else {
            OUT(ans);
        }
    }
    return 0;
}