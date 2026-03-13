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
    while (tt--) {
        int64_t n, x, y;
        cin >> n >> x >> y;
        vector<int> a(n);
        for (auto& i : a) cin >> i;
        int64_t sum = accumulate(a.begin(), a.end(), (int64_t)0);
        std::swap(x, y);
        x = sum - x;
        y = sum - y;
        sort(a.begin(), a.end());

        int64_t ans = 0;
        for (int i = 0; i < n; i++) {
            int l = lower_bound(a.begin(), a.end(), x - a[i]) - a.begin();
            int r =lower_bound(a.begin(), a.end(), y - a[i] + 1) - a.begin();
            ans += r - l;
            if (l <= i && i < r) ans--;
        }
        ans /= 2;
        cout << ans << '\n';
    }
    return 0;
}