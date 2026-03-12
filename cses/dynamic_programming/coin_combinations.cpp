/**
 * Problem: Coin Combinations I
 * Algorithm: Dynamic Programming
 * Time Complexity: O(N * X)
 */
#include <iostream>
#include <vector>

const int mod = 1e9 + 7;
const int MAX_TARGET = 1e7 + 5;

void addi(int& a, int b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    } 
}

int dp[MAX_TARGET];

using namespace std;

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
    for (int i = 0; i <= x; i++) {
        for (int c : coins) {
            if (i - c >= 0) {
                addi(dp[i], dp[i-c]);
            }
        }
    }

    cout << dp[x] << endl;

    return 0;
}