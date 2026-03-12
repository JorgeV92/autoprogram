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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;
    while (tt--) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n), b(n);
        FOR(i,0,n) { cin >> a[i]; } 
        FOR(i,0,n) { cin >> b[i]; }
        vector<int> pos(n);
        FOR(i,0,n) {
            pos[i] = max(a[i], b[i]);
        }
        vector<int> suf(n);
        suf[n-1] = pos[n-1];
        ROF(i,n-2,0) {
            suf[i] = max(pos[i], suf[i+1]);
        }
        vector<ll> pref(n);
        pref[0] = suf[0];
        FOR(i,1,n) {
            pref[i] = pref[i-1] + suf[i];
        }

        FOR(k,0,q) {
            int l , r;
            cin >> l >> r;
            l--; r--;
            ll ans = pref[r];
            if (l > 0) ans -= pref[l-1];
            cout << ans << " ";
        }
        cout << '\n';
    }    
    return 0;
}