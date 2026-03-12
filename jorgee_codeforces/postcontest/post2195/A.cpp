#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    int tt;
    std::cin >> tt;
    while (tt--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        for (int i = 0; i < n; i++) 
            std::cin >> a[i];
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (a[i] == 67) {
                found = true;
                break;
            }
        }
        if (found) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}