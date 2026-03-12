#include <iostream>
#include <vector>

void run() {
    int n;
    std::cin >> n;
    int even = 0, odd = 0;
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        if (x & 1) odd++;
        else even++;
    }
    std::cout << std::min(odd, even) << "\n";
}

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    int tt;
    std::cin >> tt;
    while (tt--) {
        run();
    }
    return 0;
}