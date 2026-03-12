/**
 * Problem: Minimizing Coins
 * Algorithm: Dynamic Programming (Optimization)
 * Time Complexity: O(N * X)
 */

#include <iostream>
#include <vector>

using namespace std;

const int inf = 1e9;
const int MAX_TARGET = 1e6 + 5;

// dp[x] - is the minimum number of coins to achieve sum x.
int dp[MAX_TARGET];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i <= x; i++) {
        dp[i] = inf;
    }
    
    dp[0] = 0;
    // Go through every su, from 1 to x
    for (int j = 1; j <= x; j++) {
        // Try every coin for the current sum j
        for (int c : arr) {
            //  is using this coin is valid (doesnt result in negative sum)
            if (j - c >= 0) {
                // dp[i] is the minimum of:
                // 1. Its current value
                // 2. 1 (current coint) + optimal way to make the remainder (j - c)
                dp[j] = min(dp[j], dp[j-c] + 1);
            }
        }
    }

    if (dp[x] == inf) {
        cout << -1 << endl;
    } else {
        cout << dp[x] << endl;
    }

    return 0;
}