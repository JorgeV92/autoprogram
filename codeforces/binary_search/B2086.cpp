#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <numeric>
using namespace std;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--){
        int64_t n, k, x;
        cin >> n >> k >> x;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int64_t sum = accumulate(a.begin(), a.end(), (int64_t)0);
        int64_t ans = 0;
        int t = std::min<int64_t>(k-1, (x-1)/sum);
        ans += 1LL * t * n;
        int64_t cur = sum * t;
        for (int i = 0; i <= n; i++) {
            if (cur < x) {
                ans++;
            }
            if (i < n) {
                cur += a[n-1-i];
            }
        }
        ans = 1LL * n * k + 1 - ans;
        cout << ans << '\n';
    }
    return 0;
}