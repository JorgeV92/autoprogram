#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>

using namespace std;

void solve() {
    int64_t s, m;
    cin >> s >> m;
    int64_t low = m & -m;
    if (s % low) {
        cout << -1 << '\n';
        return;
    }

    int64_t lo = 0, hi = s;
    while (lo < hi) {
        int64_t x = (lo + hi) >> 1;
        
        int64_t res = s;
        for (int i= 59; ~i; i--) {
            if ((m >> i) & 1) {
                res -= min(res >> i, x) << i;
            }
        }
        if (res == 0) {
            hi = x;
        } else {
            lo = x + 1;
        }
    }

    cout << lo << "\n";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}