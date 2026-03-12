#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    int tt;
    std::cin >> tt;
    while (tt--) {
        int n, x, y;
        std::cin >> n >> x >> y;
        std::vector<int> v(n);
        for (int i =0 ;i < n; i++)
            std::cin >> v[i];
        long long total = 0;
        for (int i =0 ;i < n; i++) {
            total += (v[i]/x);
        }
        long long ans= 0;
        for (int i = 0; i < n; i++) {
            long long trans = (total - (v[i]/x))* y + v[i];
            ans = std::max(ans, trans);
        } 
        std::cout << ans << '\n';
    }
    return 0;
}