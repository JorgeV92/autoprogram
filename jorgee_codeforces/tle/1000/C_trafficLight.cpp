#include <iostream>
#include <vector>
#include <string>
#include <string_view>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        char c;
        string s;
        cin >> n;
        cin >> c;
        cin >> s;
        if (c == 'g') {
            cout << 0 << '\n';
            continue;
        }
        s += s;
        int mx = -1;
        int g = -1;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == 'g') g = i;
            if (s[i] == c) {
                mx = max(mx, g - i);
            }
        } 
        cout << mx << '\n';
    }
    return 0;
}