#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

void logicalOperations(int n, int x) {
    int64_t ans = x, mask;
    n -= 1;
    for (mask = 1; n > 0; mask <<= 1) {
        if ((mask & x) == 0) {
            ans |= (n & 1) * mask;
            n >>= 1;
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
        int64_t n, x;
        cin >> n >> x;
        n -= 1;
    
        vector<int> X(64, 0), N(64, 0);
        int ans = 0, bit;
        for (int i = 0; i < 64; i++) {
            bit = (x >> i) & 1;
            X[i] = bit;
            bit = (n >> i) & 1;
            N[i] = bit;
        }

        int pX = 0, pN = 0;
        while (pX < 63) {
            while (X[pX] != 0 && pX < 63) {
                ++pX;
            }
            X[pX++] = N[pN++];
        } 
        for (int i = 0; i < 64; i++) {
            if (X[i]) {
                ans += ((int64_t)1 << i);
            }
        }

        cout << ans << endl;
    }
    return 0;
}