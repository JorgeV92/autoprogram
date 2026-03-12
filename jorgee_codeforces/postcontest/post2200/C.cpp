#include <iostream>
#include <vector>
#include <string>
#include <stack>

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::stack<char> st;

    for (int i = 0; i < n; i++) {
        if (st.empty() || st.top() != s[i]) {
            st.push(s[i]);
        } else {
            st.pop();
        }
    }
    if (st.empty()) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
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