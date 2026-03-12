#include <iostream>
#include <vector>
#include <string>
#include <cstdint>

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;

    int64_t ans = 1e18;
    for (auto c : {'a', 'b'}) {
        std::vector<int> p;
        for (int i =0; i < n; i++) {
            if (s[i] == c) {
                p.push_back(i);
            }
        }
        if (p.empty()) continue;
        int k = p.size()/2;
        int m = p[k];
        int64_t res = 0;
        for (int i = 0; i < p.size(); i++) {
            res += std::abs(m - k + i - p[i]);
        }
        ans = std::min(ans, res);
    }
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    int tt;
    std::cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;   
}