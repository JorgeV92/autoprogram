#include <iostream>
#include <vector>
#include <string>

using ll = long long;

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    ll ans = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i-1])
            ans++;
    }
    if (ans != n && s[0] != s[n-1]) 
        ans++;
    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt;
    std::cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}