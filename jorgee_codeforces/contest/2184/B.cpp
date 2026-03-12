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
    cin >> t;
    while (t--) {
        ll s, k, m;
        cin >> s >> k >> m;
        ll ans = 0;
        ll i = m/k;
        ll rem = m%k;
        ll start;
        if (s <= k) {
            start = s;
        } else {
            if (i % 2 == 0) {
                start = s;
            } else {
                start = k;
            }
        }
        ans = max(0LL, start-rem);
        OUT(ans);
    }
    return 0;
}