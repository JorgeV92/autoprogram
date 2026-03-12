#include <iostream>
#include <algorithm>
#include <vector>

void run() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    if (std::is_sorted(arr.begin(), arr.end())) {
        std::cout << n << "\n";
    } else {
        std::cout << 1 << "\n";
    }
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