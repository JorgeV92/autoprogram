#include <iostream>
#include <vector>
#include <cstring>
#include <string>

using namespace std; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> r;
    for (int i = 0; i < 1000000; i++) {
        string s = to_string(i);
        int cnt = 0;
        for (char c : s) {
            if (c != '0')
                cnt++;
        }
        if (cnt == 1) r.push_back(i);
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int ans = 0;
        for (int x : r) {
            if (x <= n) {
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}