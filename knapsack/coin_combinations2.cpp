#include <iostream>
#include <vector>
#include <cstring>


using namespace std;


// Now we want the number of distinct ordered ways we can 
// produce a sum X using the available coins.

const int MOD = 1e9 + 7;

int main() {

    int n, x;
    cin >> n >> x;
    
    vector<int> coins(n);
    for (int& a : coins) {
        cin >> a;
    }

    vector<int> dp(x+1);
    dp[0] = 1;
    
    for (int i = 1; i <= n; ++) {
        for (int w = 0; w <= x; w++) {
            if (w - coins[i-1] >= 0) { 
                dp[w] += dp[w -coins[i-1]];
                if (dp[w] >= MOD) {
                    dp[w] -= MOD;
                }
            }
        }
    }

    cout << dp[x] << endl; 

    return 0;
}
