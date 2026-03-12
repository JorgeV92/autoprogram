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
        int ans = 0;
        bool found = false;
        for (int i =0 ; i < n; i++) {
            int j = i+1;
            int k = i+2;
            if (j < n && k < n && s[i] == '.' 
                && s[j] == '.' && s[k] == '.') {
                    found = true;
            }
            if (s[i] == '.') ans += 1;
        }
        if (found) {
            cout << 2 << endl;
        } else {
            cout << ans << endl;
        }
    
    }
    return 0;
}