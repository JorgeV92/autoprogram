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
        string s;
        cin >> s;
        int n = s.size();
        int Y = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'Y')
                Y++;
        }
        if (Y >= 2) {
            cout << "NO\n";
        }  else {
            cout << "YES\n";
        }
    }
    return 0;
}