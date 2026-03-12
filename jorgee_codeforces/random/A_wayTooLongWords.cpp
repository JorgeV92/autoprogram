#include <iostream>
#include <vector>
#include <string>

using namespace std; 

int main() {    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s.length() <= 10) {
            cout << s << endl;
            continue;
        }
        int sz = s.size() - 2;
        char f = s[0];
        char l = s.back();
        string tmp = f + to_string(sz) + l;
        cout << tmp << endl;
        
    }
    return 0;
}