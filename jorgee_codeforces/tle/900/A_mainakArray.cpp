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

const int inf = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n; 
        cin >> n;
        vector<int> arr(n);
        FOR(i,0,n) {
            cin >> arr[i];
        }
        int ans = -inf;

        FOR(i,0,n) {
            ans = max(ans, arr[(i-1+n)%n] -  arr[i]);
        }

        FOR(i,1,n) {
            ans = max(ans, arr[i] - arr[0]);
        }

        FOR(i,0,n-1) {
            ans = max(ans, arr[n-1] - arr[i]);
        }

        OUT(ans);
    }

    return 0;
}