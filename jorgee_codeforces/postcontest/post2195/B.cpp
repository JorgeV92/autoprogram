#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n+1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    for (int i = 1; i <= n; i += 2) {
        std::vector<int> pos, val;
        for (int j = i; j <= n; j *= 2) {
            pos.push_back(j);
            val.push_back(a[j]);
        }
        std::sort(val.begin(), val.end());
        if (pos != val) {
            std::cout << "NO\n";
            return;
        }
    }
    std::cout << "YES\n";
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