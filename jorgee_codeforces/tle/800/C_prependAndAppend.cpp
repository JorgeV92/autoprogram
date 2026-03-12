#include <iostream>
#include <vector>
#include <string>

using namespace std; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ops = n;
        int l =0, r = s.size() - 1;
        while (l < r) {
            if (s[l] == '0' && s[r] == '1') {
                ops -= 2;
                l++; r--;
            } else if (s[l] == '1' && s[r] == '0') {
                ops -= 2;
                l++; r--;
            } else {
                break;
            }
        }
        cout << ops << endl;
    }
    return 0;
}