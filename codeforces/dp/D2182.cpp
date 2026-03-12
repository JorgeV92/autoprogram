#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

const int mod = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n), dep(n);
    for (int i = 1; i < n; i++) {
        cin >> p[i];
        --p[i];
        dep[i] = dep[p[i]] + 1;
    }
    vector<vector<int>> lvs(n);
    for (int i = 0; i < n; i++) {
        lvs[dep[i]].push_back(i);
    }
    vector<int> dp(n,0);
    dp[0] = 1;
    int sum = 1;
    int ans = 1;
    for (int d = 1; d < n; d++) {
        if (lvs[d].empty())
            continue;
        int nsum = 0;
        for (int x : lvs[d]) {
            dp[x] = sum;
            if (d > 1) {
                dp[x] -= dp[p[x]];
                if (dp[x] < 0) dp[x] += mod;
            }
            nsum += dp[x];
            if (nsum >= mod) nsum -= mod;
        }
        sum = nsum;
        ans += sum;
        if (ans >= mod) ans -= mod;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;   
}