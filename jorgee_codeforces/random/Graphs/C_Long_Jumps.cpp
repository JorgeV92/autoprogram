#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std; 

constexpr int N = 2e5 + 7;

int dp[N];

void solve() {
    int n;
    cin >> n;
    memset(dp, 0, sizeof(dp));
    vector<int> a(n);
    for (int i  =0 ; i < n; i++) {
        cin >> a[i];
    }

    for (int i = n-1; i >= 0; i--) {
        dp[i] = a[i];
        int j = i + a[i];
        if (j < n) 
            dp[i] += dp[j];
    }

    cout << *max_element(dp, dp+n) << endl;
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