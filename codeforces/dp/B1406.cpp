#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int64_t> a(n);
        int64_t mx = -1e18;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            mx = max(mx, a[i]);
        }
        sort(a.begin(), a.end(), [&](const auto& x, const auto& y) {
            return abs(x) > abs(y);
        });
        if (mx < 0) {
            cout << a[n-1]*a[n-2]*a[n-3]*a[n-4]*a[n-5] << "\n";
            continue;
        }
        int64_t ans = a[0]*a[1]*a[2]*a[3]*a[4];
        for (int i = 5; i < n; i++) {
            for (int j = 0; j < 5; j++) {
                int64_t tmp = a[i];
                for (int k = 0; k < 5; k++) {
                    if (k != j) tmp *= a[k];
                }
                ans = max(ans, tmp);
            }
        }
        cout << ans << '\n';
    }
    return 0;   
}