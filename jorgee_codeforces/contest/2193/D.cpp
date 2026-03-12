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
        int n;
        cin >> n;
        vector<ll> a(n), b(n);
        FOR(i,0,n) { cin >> a[i]; }
        FOR(i,0,n) { cin >> b[i]; }
        sort(all(a), greater<ll>());
        ll mx = 0;
        ll neededSwords = 0;
        FOR(i,0,n) {
            neededSwords += b[i];
            if (neededSwords > n) break;
            ll x = a[neededSwords-1];
            ll score = x * (i + 1);
            chmax(mx, score);
        }
        OUT(mx);
    }
    return 0;
}