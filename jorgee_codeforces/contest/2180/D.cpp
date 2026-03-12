/**
 *    Submitted for educational reasons 
 *    Credit solution tourist with small modifcations
 *    see original solution at 
 *    https://codeforces.com/contest/2180/submission/354127961
**/

#include <iostream>
#include <vector>
#include <cstdint>

using namespace std; 

#define ll long long 
const int64_t inf = int64_t(1e18);

void solve() {
    int n;
    cin >> n;

    vector<int64_t> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    if (n < 2) {
        cout << 0 << endl;
        return;
    }
    int64_t low = 0, high = x[1] - x[0];
    int ans = 0;
    for (int i = 1; i < n; i++) {
        auto d = x[i] - x[i-1];
        swap(low, high);
        high = d - high;
        low = d - low;
        if (i < n - 1) {
            high = min(high, x[i+1] - x[i]);
        }
        if (low < 0) {
            low = 0;
        }
        if (low >= high) {
            low = 0;
            high = (i == n-1 ? inf : x[i+1] - x[i]);
        } else {
            if (low < 0) {

            }
            ans += 1;
        }
    }

    cout << ans << endl;
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