#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int cnt[2][26]{};
        for (int i = 0; i < n; i++) {
            cnt[i%2][s[i]-'a']++;
        }
        int ans = n;
        if (n % 2 ==0 ){
            ans = n - *max_element(cnt[0], cnt[0] + 26) - *max_element(cnt[1], cnt[1] + 26);
        }

        for (int i = n-1; i >= 0; i--) {
            cnt[i%2][s[i]-'a']--;
            if (n% 2 == 1) {
                ans = min(ans, n - *max_element(cnt[0], cnt[0]+26) - *max_element(cnt[1], cnt[1]+26));
            }
            cnt[(i+1)%2][s[i]-'a']++;
        }
        cout << ans << "\n";
    }
    return 0;
}