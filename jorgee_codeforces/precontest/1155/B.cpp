#include <iostream>
#include <string>
#include <vector>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    int cnt8 = 0;
    for (int i = 0; i <= n-11; i++) {
        cnt8 += (s[i] == '8');
    }
    if (cnt8 * 2 <= n-11) {
        std::cout << "NO\n";
    } else {
        std::cout << "YES\n";
    }
    return 0;
}