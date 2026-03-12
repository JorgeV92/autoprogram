
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

const int MAX_TARGET = 5005;
const int mod = 998244353;

int dp[MAX_TARGET];

void addi(int& a, int b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q, K;
    cin >> Q >> K;

    vector<int> box;
    dp[0] = 1;
    while (Q--) {
        char t;
        int x;
        cin >> t >> x;
        if (t == '+') {
            // Add a new ball of value x

            // Iterate from K down to x. We iterate downwards to ensure that 
            // dp[k-x] uses the old value (before the current ball was considered).
            for (int k = K; k >= x; k--) {
                // New ways to make sum k come from adding the new ball x
                // to every way of making sum k-x
                dp[k] = (dp[k] + dp[k-x]);

                if (dp[k] >= mod) {
                    dp[k] -= mod;
                }
            }
        } else {
            // Remove a specific vall of value x

            // Iterate from x up to K. We iterate upwards to ensure that 
            // dp[k-x] uses the NEW (post-removal) value.
            for (int k = x; k <= K; k++) {
                // Reversal: Ways to make sum k without the removed ball x 
                // (dp[k-x]) are removed from the current total ways (dp[k]).
                // The ways to make sum k-x are already updated to reflect 
                // the state *after* the ball x is removed.
                dp[k] = (dp[k] - dp[k-x]);

                if (dp[k] < 0) {
                    dp[k] += mod;
                }
            }
        }

        cout << dp[K] << endl;
    }

    return 0;
}