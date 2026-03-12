/**
 * Problem: Coin Combinations II
 * Algorithm: Dynamic Programming (Unordered / Knapsack-style)
 * Time Complexity: O(N * X)
 */
#include <iostream>
#include <vector>

using namespace std;

const int MAX_TARGET = 1e7 + 5;
const int mod = 1e9 + 7;

void addi(int& a, int b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}

int dp[MAX_TARGET];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= x; j++) {
            if (j - coins[i-1] >= 0) {
                addi(dp[j], dp[j-coins[i-1]]);
            }
        }
    }

    // or 
    /*
    // The Coin loop is now on the OUTSIDE
    for (int c : coins) {
        
        // We iterate from the coin's value up to the target
        // (We can't make a sum smaller than 'c' using 'c')
        for (int i = c; i <= target; i++) {
            // Add the ways to make the remainder using the CURRENT set of allowed coins
            addi(dp[i], dp[i-c])
        }
    }
    */

    cout << dp[x] << endl;


    return 0;
}