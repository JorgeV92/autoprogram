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
        ll n, m, h;
        cin >> n >> m >> h;
        vector<ll> A(n), B(n);
        FOR(i,0,n) {
            cin >> A[i];
            B[i] = A[i];
        }
        vector<int> last_mod(n,-1);
        int crash = -1;
        FOR(k,0,m) {
            int b;
            ll c;
            cin >> b >> c;
            b--;
            if (last_mod[b] <= crash) {
                B[b] = A[b];
            }
            B[b] += c;
            last_mod[b] = k;
            if (B[b] > h) {
                crash = k;
            }
        }
        FOR(i,0,n) {
            if (last_mod[i] <= crash) {
                cout << A[i] << ' ';
            } else {
                cout << B[i] << ' ';
            }
        }
        cout << '\n';

    } 
    return 0;
}