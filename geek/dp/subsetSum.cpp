#include <iostream>
#include <vector>

using namespace std;

bool isSubsetSumRec(vector<int>& arr, int n, int sum) {
    if (sum == 0) return true;
    if (n == 0) return false;
    if (arr[n-1] > sum) 
        return isSubsetSumRec(arr, n-1, sum);
    return isSubsetSumRec(arr, n-1, sum) || isSubsetSumRec(arr,n-1, sum-arr[n-1]);
}

bool isSubsetSumR(vector<int>& arr, int sum) {
    return isSubsetSumRec(arr, arr.size(), sum);
}

bool isSubsetSumTopDown(vector<int>& arr, int n, int sum, vector<vector<int>>& memo) {
    if (sum == 0) return true;
    if (n <= 0) return false;
    if (memo[n][sum] != -1) 
        return memo[n][sum];
    if (arr[n-1] > sum) 
        return memo[n][sum] = isSubsetSumTopDown(arr, n-1, sum, memo);
    else {
        return memo[n][sum] = isSubsetSumTopDown(arr, n-1,sum,memo) || 
                                isSubsetSumTopDown(arr, n-1, sum-arr[n-1], memo);
    }
}

bool isSubsetSumTD(vector<int>& arr, int sum) {
    int n = arr.size();
    vector<vector<int>> memo(n+1, vector<int>(sum+1, -1));
    return isSubsetSumTopDown(arr, n, sum, memo);
}

bool isSubsetSumBottomDown(vector<int>& arr, int sum) {
    int n = arr.size();
    vector<vector<bool>> dp(n+1, vector<bool>(sum+1, false));
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j < arr[i-1]) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = dp[i-1][j] || dp[i-1][j - arr[i-1]];
            }
        }
    }
    return dp[n][sum];
}

bool isSubsetSumBDopt(vector<int>& arr, int sum) {
    int n= arr.size();
    vector<bool> prev(sum+1, false), curr(sum+1);
    prev[0] = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j < arr[i-1])
                curr[j] = prev[j];
            else 
                curr[j] = (prev[j] || prev[j-arr[i-1]]);
        }
        prev = curr;   
    }
    return prev[sum];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int sum = 9;

    if (isSubsetSumBDopt(arr, sum))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}