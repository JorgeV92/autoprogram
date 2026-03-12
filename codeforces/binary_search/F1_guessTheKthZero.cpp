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

    int n, t, k;
    cin >> n >> t >> k;

    int l = 1, r = n;
    while (l < r) {
        int mid = (l + r) / 2;
        cout << "? " << l << " " << mid << endl;
        int sum;
        cin >> sum;
        int zeros = (mid - l + 1) - sum;
        if (zeros >= k) {
            r = mid;
        } else {
            l = mid + 1;
            k -= zeros;
        }
    }
    cout << "! " << l << endl;
    
    return 0;
}