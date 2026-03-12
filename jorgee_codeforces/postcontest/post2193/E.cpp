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

const int maxn = 1e6+3;
int a[maxn], dp[maxn];
int n, q;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) dp[i] = 1e9;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[a[i]] = 1;
    }
    for (int i= 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            dp[j] = min(dp[j], dp[i] + dp[j/i]);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (dp[i] == 1e9)
            dp[i] = -1;
        cout << dp[i] << ' ';
    }
    cout << '\n';

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