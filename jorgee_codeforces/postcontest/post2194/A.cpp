#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    int tt;
    std::cin >> tt;
    while (tt--) {
        long long n, w;
        std::cin >> n >> w;
        std::cout << (n-(n/w)) << '\n';
    }
    return 0;
}