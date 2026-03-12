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
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define OUT(x) cout << x << '\n'
#define all(x) (x).begin(), (x).end()
#define FOR(i,a,b) for(int i = (a); i < (b); i++) 
#define FORE(i,a,b) for(int i = (a); i <= (b); i++)
#define ROF(i,a,b) for(int i = (a); i >= (b); i--)

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return false;}
template<class T> inline bool chmin(T& a, T b) { if ( a > b) { a = b; return 1;} return false;}

using ll = long long;

void solve() {
    ll a, b, c;
    cin >> a >> b >> c;
    int aa = b - (c-b);
    if (aa >= a && aa % a == 0 && aa != 0) {
        cout << "YES\n";
        return;
    }
    int bb = a + (c - a) /2;
    if (bb >= b && (c-a)%2 == 0 && bb % b == 0 && bb != 0) {
        cout << "YES\n";
        return;
    }
    int cc = a + 2*(b-a);
    if (cc >= c && cc % c == 0 && cc != 0) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
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