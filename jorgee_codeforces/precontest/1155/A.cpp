#include <iostream>
#include <vector>
#include <string>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    for (int i = 0; i < n-1; i++) {
        if (s[i] > s[i+1]) {
            std::cout << "YES\n";
            std::cout << i+1 << " " << i+2 << "\n";
            return 0;
        }
    } 
    std::cout << "NO\n";
    return 0;
}