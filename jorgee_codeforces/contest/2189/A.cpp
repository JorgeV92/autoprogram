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
        int n, h, l;
        cin >> n >> h >> l;
        vector<int> arr(n); 
        int cnt_both = 0;
        int cnt_rem = 0;
        int min_dim = min(h, l);
        int max_dim = max(h, l);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            if (arr[i] <= min_dim) {
                cnt_both++;
            } else if (arr[i] <= max_dim) {
                cnt_rem++;
            }
        }
        int total = min(cnt_both, (cnt_both + cnt_rem) / 2);
        cout << total << '\n';
    }
    return 0;
}