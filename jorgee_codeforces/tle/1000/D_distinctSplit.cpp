#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n ;
        cin >> n;
        string s;
        cin >> s;
        vector<int> cntl(26), cntr(26);
        int res = 0;
        for (auto c : s) {
            res += !cntr[c - 'a']++;
        }
        int ans = res;
        for (auto c : s) {
            res += !cntl[c-'a']++;
            res -= !--cntr[c-'a'];
            ans = max(ans, res);
        }
        cout << ans << '\n';
    }
    return 0;   
}