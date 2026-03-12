#include <iostream>
#include <vector>
#include <string>

using namespace std; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    using ll = long long;


    string s;
    cin >> s;
    int sz = s.size();
    for (int i = 0; i < sz; i++) {
        int d = s[i] - '0';
        if (d > 9 - d) {
            if (i == 0 && d == 9) 
                continue;
            s[i] = (9 - d) + '0';
        }
    }

    cout << s << '\n';

    return 0;
}