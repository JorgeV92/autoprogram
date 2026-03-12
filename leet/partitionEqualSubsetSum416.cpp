#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

bool canPartition(vector<int>& nums) {
    int n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);
    int T = sum / 2;
    if (sum & 1) return false;

    vector<vector<bool>> dp(n+1, vector<bool>(T+1));
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= T; w++) {
            dp[i][w] = dp[i-1][w];
            if (w >= nums[i-1]) {
                dp[i][w] = dp[i][w] || dp[i-1][w-nums[i-1]];
            }
        }
    }

    return dp[n][T];
}

bool canPartition(vector<int>& nums)  {
    int n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum & 1) return false;
    int T = sum / 2;
    vector<bool> dp(T+1);
    dp[0] = true;
    for (int x : nums) {
        for (int w = T; w >= x; w--) {
            dp[w] = dp[w] || dp[w-x];
        }
    }
    return dp[T];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> A{1, 5, 11, 5};
    cout << canPartition(A) << endl;
    return 0;
}