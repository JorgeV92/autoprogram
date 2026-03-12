#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> s(n);
    for (int i =0 ;i < n; i++) {
        std::cin >> s[i];
    }
    std::vector<int> p(n);
    std::iota(p.begin(), p.end(), 0);
    
    for (int i = 0; i < n;) {
        int j = i;
        while (j < n && s[i] == s[j]) j++;
        if (j - i == 1) {
            std::cout << "-1\n";
            return;
        }
        std::rotate(p.begin() + i, p.begin()+ i+1, p.begin() + j);
        i = j;
    }
    for (int ii = 0; ii < n; ii++) {
        std::cout << p[ii] + 1<< " \n"[ii == n-1];
    }
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