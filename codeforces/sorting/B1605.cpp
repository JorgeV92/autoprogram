#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    int tt;
    cin >>tt;
    while (tt--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int cnt0 = count(s.begin(), s.end(), '0');
        vector<int> p;
        for (int i = 0; i < n; i++) {
            if (s[i] == (i < cnt0 ? '1' : '0')) {
                p.push_back(i);
            }
        }
        if (p.empty()) {
            cout << 0 << '\n';
        } else {
            cout << 1 << '\n';
            cout << p.size();
            for (auto i : p) {
                cout << " " << i + 1;
            }
            cout << '\n';
        }
    }
    return 0;
}