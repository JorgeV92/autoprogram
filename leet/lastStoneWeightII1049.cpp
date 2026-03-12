#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int lastStoneWeightII(vector<int>& stones) {
    int n = stones.size();
    int sum = accumulate(stones.begin(), stones.end(), 0);
    int T = sum / 2;
    
    vector<vector<int>> dp(n+1, vector<int>(T+1));
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= T; w++) {
            dp[i][w] = dp[i-1][w];
            if (w >= stones[i-1]) {
                dp[i][w] = max(
                    dp[i][w],
                    dp[i-1][w-stones[i-1]] + stones[i-1]
                );
            }
        }
    }

    int sum1 = dp[n][T];
    int sum2 = sum - sum1;
    return sum2 - sum1;
}

int lastStoneWeightIIOpt(vector<int>& stones) {
    int n = stones.size();
    int sum = accumulate(stones.begin(), stones.end(), 0);
    int T = sum / 2;
    vector<int> dp(T+1);
    for (const int x : stones) {
        for (int w = T; w >= x ; w--) {
            dp[w] = max(dp[w], dp[w-x] + x);
        } 
    }
    return sum - 2*dp[T];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}