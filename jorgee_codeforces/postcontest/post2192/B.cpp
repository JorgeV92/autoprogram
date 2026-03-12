#include <iostream>
#include <vector>
#include <string>

void program() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    int c1 = 0, c0 = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') 
            c1++;
        else 
            c0++;
    }

    if (c0 % 2 != 0) {
        std::cout << c0 << "\n";
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') 
                std::cout << i + 1 << " ";
        }
        std::cout << '\n';
    } else if (c1 % 2 == 0) {
        std::cout << c1 << '\n';
        if (c1 != 0) {
            for (int i =0 ; i < n; i++) {
                if (s[i] == '1') {
                    std::cout << i + 1 << ' ';
                }
            }
            std::cout << '\n';
        }
    } else {
        std::cout << "-1\n";
    }
} 

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    int T;
    std::cin >> T;
    while (T--) {
        program();
    }
    return 0;
}