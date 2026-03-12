#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <array>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, q;
        cin >> n >> q;
        string a, b;
        cin >> a >> b;
        vector<array<int, 26>> pre(n+1);
        for (int i = 0; i < n; i++) {
            pre[i+1] = pre[i];
            pre[i+1][a[i]-'a']++;
            pre[i+1][b[i]-'a']--;
        }
        while (q--) {
            int l, r;
            cin >> l >> r;
            l--;
            int ans = 0;
            for (int c = 0; c < 26; c++) {
                ans += max(0, pre[r][c]- pre[l][c]);
            }
            cout << ans << "\n";
        }
    }
    return 0;
}