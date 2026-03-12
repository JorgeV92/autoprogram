#include <iostream>
#include <vector>
#include <cstring>
#include <climits>

using namespace std;

// The problem now is how can we achieve all posiible distinct ways 
// that we can sum to W using the available coins?

const int MOD = 1e9 + 7; 

int main() {

    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    for (int& a : coins) {
        cin >> a;
    }
    // dp[i] - is the number of distinct ways we can achieve sum i
    vector<int> dp(x+1);
    dp[0] = 1;
    
    for (int w = 1; w <= x; w++) {
        for (int i = 0; i < n; i++) {
            if (w - coins[i] >= 0) {
                dp[w] += dp[w - coins[i]];
                if (dp[w] >= MOD) {
                    dp[w] -= MOD;
                }
            }
        }
    }

    cout << dp[x] << endl;

    return 0; 
}

