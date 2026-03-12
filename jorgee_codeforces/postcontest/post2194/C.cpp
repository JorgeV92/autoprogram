#include <iostream>
#include <vector>
#include <string>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using i128 = __int128;
using u128 =  unsigned __int128;

void solve() {
    int n, k;
    std::cin >> n >> k;

    std::vector<std::string> s(k);
    for (int i = 0; i < k; i++){
        std::cin >> s[i];
    }
    
    for (int d = 1; d <= n; d++) {
        if (n % d) {
            continue;
        }
        std::string t;
        for (int j = 0; j < d; j++) {
            int a = (1 << 26) - 1;
            for (int x = j; x < n; x += d) {
                int b = 0;
                for (int i = 0; i < k; i++) {
                    b |= 1 << (s[i][x] - 'a');
                }
                a &= b;
            }
            if (!a) break;
            t += 'a' + __builtin_ctz(a);
        }
        if (t.size() < d) continue;
        while (t.size() < n) {
            t += t.substr(0, d);
        }
        std::cout << t << "\n";
        return;
    }
}

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    int tt;
    std::cin >> tt;
    while (tt--) {
        solve();
    }    
}