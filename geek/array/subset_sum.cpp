#include <iostream>
#include <vector>

using namespace std;

// Given an array of non-negtaive integers and a value sum, the 
// task is to check if there is a subset of the given array whose
// sum is equal to the given sum.

// Brute force using recursion
// O(2^n) time and O(n) space

bool isSubsetSumBruteForce(vector<int>& arr, int k) {
    int n = arr.size();

    auto dfs = [&](auto&& dfs, int idx, int sum) -> bool {
        if (sum == 0) return true;
        if (idx == 0) return false;
        if (arr[idx] > sum) 
            return dfs(dfs, idx-1, sum);
        return dfs(dfs, idx-1, sum) || dfs(dfs, idx-1, sum-arr[idx]);
    };
    
    return dfs(dfs, n-1, k);
}

// Top-Down DP (Memoization)
// O(k * n) time and O(k * n) space

bool isSubsetSumTopDownDP(vector<int>& arr, int k) {
    int n = arr.size();
    vector<vector<int>> memo(n+1, vector<int>(k+1, -1));

    auto dfs = [&](auto&& dfs, int idx, int sum) -> bool {
        if (sum == 0) return true;
        if (idx == 0) return false;
        if (memo[idx][sum] != -1) return memo[idx][sum];

        if (arr[idx] > sum) 
            return memo[idx][sum] = dfs(dfs, idx-1, sum);
        else {
            return memo[idx][sum] = dfs(dfs, idx-1,sum) 
                                    || dfs(dfs, idx-1, sum-arr[idx]);
        }   
    };

    return dfs(dfs, n-1, k);
}

// Bottom-Up DP (Tabulation)
// O(k * n) tima and O(k * n)

bool isSubsetSumBottomUpDP(vector<int>& arr, int k ) {
    int n = arr.size();
    vector<vector<bool>> dp(n+1, vector<bool>(k+1, false));
    dp[0][0] = true;
    for (int i = 1; i < n; i++) {
        for (int j = k; j >= 0; j--) {
            dp[i][j] = dp[i-1][j];
            if (j - arr[i-1] >= 0) {
                dp[i][j] = dp[i][j] || dp[i-1][j-arr[i-1]];
            }
        }
    }
    return dp[n][k];
}

bool isSubsetSumBottomUpDPOpt(vector<int>& arr, int k ) {
    int n = arr.size();
    vector<bool> dp(k+1, false);
    dp[0] = true;
    for (int i = 1; i <= n; i++) {
        vector<bool> new_dp(k+1);
        for (int j = 0; j <= k; j++) {
            if (j < arr[i-1]) {
                new_dp[j] = dp[j];
            } else {
                new_dp[j] = (dp[j] || dp[j-arr[i-1]]);
            }
        }
        dp = new_dp;
    }
    return dp[k];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
      
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int k = 9;

    if (isSubsetSumBottomUpDPOpt(arr, k)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}