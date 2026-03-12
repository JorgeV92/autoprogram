#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    map<int,int> dp;
    int ans = 0;
    int lst = 0;
    for (int i = 0; i < n; i++) {
        int x = a[i];
        dp[x] = dp[x-1] + 1;
        if (ans < dp[x]) {
            ans = dp[x];
            lst = x;
        }
    }
    vector<int> out;
    for (int i = n-1; i >= 0; --i) {
        if (a[i] == lst) {
            out.push_back(i);
            --lst;
        }
    }
    reverse(out.begin(), out.end());
    cout << ans << "\n";
    for (auto x : out) {
        cout << x + 1 << " ";
    }
    cout << '\n';
    return 0;
}