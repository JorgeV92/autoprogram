#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    int tt;
    std::cin >> tt;
    while (tt--) {
        int n;
        std::cin >> n;
        std::vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            std::cin >> arr[i];
        }
        int mx = *std::max_element(arr.begin(), arr.end());
        int cnt = std::count(arr.begin(), arr.end(), mx);
        std::cout << cnt << "\n";
    }
    return 0;
}