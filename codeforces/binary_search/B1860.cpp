#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int tt;
    cin >>tt;
    while (tt--) {
        int64_t m, k, a1, ak;
        cin >> m >> k >> a1 >> ak;

        int64_t t = max(0LL, min(m/k, (m - a1 + k -1) / k));
        int64_t ans = max(0LL, t - ak) + max(0LL, m - t * k - a1);
        cout << ans << "\n";
    }
    return 0;
}