#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

const int mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int64_t n;
    cin >> n;
    
    auto apowb = [&](int64_t a, int64_t b) {
        int64_t res = 1;
        while (b > 0) {
            if (b & 1) {
                res *= a;
                res %= mod;
            }
            a = a * a % mod;
            b = b >> 1;
        }
        return res;
    };

    cout << apowb(2, n) << "\n";

    return 0;   
}