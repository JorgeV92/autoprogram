#include <iostream>
#include <vector>
#include <cstring>
#include <climits>

using namespace std;


const int INF = 1e9+7;

int main() {

    int n, x;
    scanf("%d%d", &n, &x);

    vector<int> coins(n);

    for (int& a : coins) {
        cin >> a;
    }

    auto solution_2d = [&]() -> void {
        // dp[i][x] - is the minimum number of coins that add up to x using the first i coins
        vector<vector<int>> dp(n+1, vector<int>(x+1, x+1));
        dp[0][0] = 0;
        
        for (int i= 1; i <= n; i++) { // O(N)
            for(int curr_sum = 0; curr_sum <= x; curr_sum++) { // O(X)
                dp[i][curr_sum] = dp[i-1][curr_sum];
                if (curr_sum >= coins[i-1]) {
                    dp[i][curr_sum] = min(dp[i][curr_sum], dp[i][curr_sum - coins[i-1]] + 1);
                }
            }
        }
            
        cout << (dp[n][x] != x+1 ? dp[n][x] : -1) << endl;

        // O(N * X)
    };

    auto solution_1d = [&]() -> void {
        // dp[w] - is the minimum number of coins to achieve weight w
        long long dp[1000001];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i <= x; i++) {
            dp[i] = INT_MAX;
        }
        dp[0] = 0; // to reach a sum of 0 we need 0 coins
        for (int i = 1; i <= n; i++) { // O(N)
            for (int w = coins[i-1]; w <= x; w++) { // O(W)
                dp[w] = min(dp[w], dp[w - coins[i-1]] + 1);
            }
        } 

        cout << (dp[x] == INT_MAX ? -1 : dp[x]) << endl;

        // O(N * W)
    };

    solution_1d();

    return 0;
}
