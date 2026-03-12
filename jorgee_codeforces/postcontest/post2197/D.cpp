#include <iostream>
#include <vector>
#include <cstdint>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        for (int i = 0; i < n; i++) 
            std::cin >> a[i];
        int64_t ans = 0;
        for (int i = 0; i < n; i++) {
            for (int s = 1; s <= a[i] && i + a[i] * s < n; s++) {
                if (a[i+a[i]*s] == s) 
                    ans++;
            }
        }

        for (int i =0 ; i < n; i++) {
            for (int s = 1; s < a[i] && i - a[i] *s >= 0; s++) {
                if (a[i-a[i]*s] == s) 
                    ans++;
            }
        }
        std::cout << ans << '\n';
    }
    
    return 0;
}