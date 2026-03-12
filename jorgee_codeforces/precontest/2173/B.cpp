#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<vector<ll>> dp(n, vector<ll>(4));
    dp[0][0] = dp[0][1] = -a[0];
    dp[0][2] = dp[0][3] = b[0];

    for (int i = 1; i < n; i++) {
        ll mxab = *max_element(dp[i-1].begin(), dp[i-1].end());
        ll mnab = *min_element(dp[i-1].begin(), dp[i-1].end());
        dp[i][0] = mxab - a[i];
        dp[i][1] = mnab - a[i];
        dp[i][2] = b[i] - mxab;
        dp[i][3] = b[i] - mnab;
    }
    cout << *max_element(dp[n-1].begin(), dp[n-1].end()) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
    return 0;   
}