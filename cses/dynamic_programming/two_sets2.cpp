/**
 * Problem: Subset Sum / Coin Sums
 * Algorithm: Dynamic Programming (0/1 Knapsack style)
 * Time Complexity: O(N * Total Sum)
 */
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;
// Maximum possible sum T = (500 * 501) / 4 ~ 62625
const int MAX_TARGET = 62626;

int dp[505][MAX_TARGET];

void addi(int& a, int b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    
    ll X = (ll)n * (n+1) / 2;
    if (X & 1) {
        cout << 0 << endl;
        return 0;
    }

    int Y = X/2;
    dp[0][0] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= Y; j++) {
            dp[i][j] += dp[i-1][j];
            if (j - i >= 0) {
                addi(dp[i][j], dp[i-1][j-i]);
            }
        }
    }
    cout << dp[n-1][Y] << endl;


    return 0;
}
