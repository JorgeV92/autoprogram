/**
 * Problem: Dice Combinations
 * Algorithm: Dynamic Programming
 * Time Complexity: O(N)
 */

#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
constexpr int mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

// dp[i] - is the number of ways to create sum i.
int dp[MAXN];

void addi(int& a, int b) {
    a += b; 
    if (a >= mod) {
        a -= mod;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    // Base case: There is 1 way to get sum 0 (do nothing)
    dp[0] = 1;

    // from sum 1 up to n
    for (int i = 1; i <= n; i++) {
        // Try every die outcome (1 through 6)
        for (int j = 1; j <= 6; j++) {
            // if i is large enough to have come from i-j
            if (i - j >= 0) {
                // Add the ways to get that previous state
                addi(dp[i], dp[i-j]);
            }
        }
    }

    cout << dp[n] << endl;
    
    return 0;
}