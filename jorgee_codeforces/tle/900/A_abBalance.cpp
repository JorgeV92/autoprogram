#include <iostream>
#include <string>
#include <vector>

using namespace std; 

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        string s;
        cin >> s;
        int n = s.size();
        if (s[0] == s[n-1]) {
            cout << s << '\n';
        } else {
            s[n-1] = s[0];
            cout << s << '\n';
        }
    }
}