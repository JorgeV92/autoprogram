#include <iostream>
#include <vector>

using namespace std;

#define ll long long
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<ll> dp(n+1, 1e9);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        ll x = i;
        while (x) {
            ll d = x%10;
            dp[i] = min(dp[i], dp[i-d]+1);
            x /= 10;
        }
    }
    cout << dp[n] << endl;
    return 0;
}