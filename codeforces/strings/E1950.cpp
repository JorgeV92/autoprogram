#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        for (int len = 1; len <= n; len++) {
            if (n % len != 0)
                continue;
            for (int i = 0; i < n && i <= len; i += len) {
                int ans = 0;
                for (int j = 0; j < n; j++) {
                    ans += (s[i + j % len] != s[j]);
                }
                if (ans <= 1) {
                    std::cout << len << "\n";
                    goto end;
                }
            }
        }
        end:;
    }
    return 0;
}