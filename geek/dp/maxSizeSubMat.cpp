#include <iostream>
#include <vector>

using namespace std; 


int maxSquare(vector<vector<int>> &mat) {
    int n = mat.size(), m = mat[0].size();
    vector<vector<int>> dp(n+1, vector<int>(m+1));
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (mat[i-1][j-1] == 0)
                continue;
            dp[i][j] = min({
                dp[i-1][j],
                dp[i][j-1],
                dp[i-1][j-1]
            }) + 1;

            ans = max(ans, dp[i][j]);
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> mat = 
        {{0, 1, 1, 0, 1}, 
        {1, 1, 0, 1, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0}};
    cout << maxSquare(mat) << endl;
    return 0;
}