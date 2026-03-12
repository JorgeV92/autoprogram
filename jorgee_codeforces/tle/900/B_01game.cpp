#include <iostream>
#include <string>
#include <vector>

using namespace std; 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        string s;
        cin >> s;
        int cnt0 = 0, cnt1 = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == '0') cnt0++;
            if (s[i] == '1') cnt1++;
        }
        int moves = min(cnt0, cnt1);
        if (moves & 1) {
            cout << "DA\n";
        } else {
            cout << "NET\n";
        }
    }
    return 0;
}