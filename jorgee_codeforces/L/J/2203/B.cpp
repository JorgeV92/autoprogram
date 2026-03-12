#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    string s;
    cin >> s;
    s[0]--;
    sort(s.begin(), s.end());
    int sum = 0;
    int res = s.size();
    for (auto x : s)  {
        sum += x - '0';
        if (sum < 9) {
            res--;
        }
    }
    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}