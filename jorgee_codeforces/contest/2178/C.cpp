#include <iostream>
#include <vector>
#include <cstring>

using namespace std; 

#define ll long long 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<ll> S(n+1);
        for (int i = n-1; i >= 0; i--) {
            S[i] = S[i+1] + a[i];
        }
        vector<ll> dp(n);
        ll X = S[n-1] + dp[n-1];
        for (int i = n-2; i >= 0; i--) {
            dp[i] = max(-S[i+1], a[i] - S[i+1] + X);
            X = max(X, S[i] + dp[i]);
        }
        cout << dp[0] << endl;
    }
    return 0;
}