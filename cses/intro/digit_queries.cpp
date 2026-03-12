#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

int64_t apowb(int64_t a, int64_t b) {
    uint64_t res = 1;
    while (b > 0) {
        if (b & 1)  {
            res *= a;
        }
        a = a * a;
        b = b >> 1;
    }
    return res;
}

void solve() {
    int64_t k;
    cin >> k;
    int64_t digits = 1;
    int64_t base = 9;

    while (k - digits * base > 0) {
        k -= digits * base;
        base *= 10;
        digits++;
    }

    int64_t index = k % digits;

    int64_t res = apowb(10, (digits-1)) + (k-1) / digits;

    if (index != 0) 
        res = res / apowb(10, digits - index);
    cout << res % 10 << "\n";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int q;
    cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}