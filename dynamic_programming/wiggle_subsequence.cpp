#include <iostream>
#include <vector>

using namespace std;


// 376. Wiggle Subsequence 
//

int wiggleMaxLength(vector<int>& A) {
    const int n = A.size();
    // dp[i][2] is max length of alternating sequence (zigzag) ending at i
    // dp[i][0] means we when down to i
    vector<vector<int>> dp(n, vector<int>(2));
    int ans = 0;
    for (int i = 0; i < n; i++) {
        dp[i][0] = dp[i][1] = 1;
        for (int j = 0; j < i; j++) {
            if (A[j] < A[i]) {
                dp[i][1] = max(dp[i][1], dp[j][0] + 1);
            }

            if (A[j] > A[i]) {
                dp[i][0] = max(dp[i][0], dp[j][1] + 1);
            }
        }
        ans = max({ans, dp[i][0], dp[i][1]});
    }
    return ans;
}
