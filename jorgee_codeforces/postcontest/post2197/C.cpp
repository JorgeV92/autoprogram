#include <iostream>
#include <vector>
#include <cstdint>

void solve() {
    int64_t p, q;
    std::cin >> p >> q;
    std::cout << (q > p &&  q <= p + p / 2 ? "Bob" : "Alice") << "\n";
}

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}