#include <iostream>
#include <vector>

using namespace std;
const int inf = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> grid{
        {4, 9, 7},
        {3, 8, 5},
        {1, 2, 6},
    };

    int n = grid.size();

   vector<vector<int>> dp(n, vector<int>(n, inf));

    dp[0][0] = grid[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i > 0) {
                dp[i][j] = min(dp[i][j],dp[i-1][j] + grid[i][j]);
            } 
            if (j > 0) {
                dp[i][j] = min(dp[i][j], dp[i][j-1] + grid[i][j]);
            }
        }
    } 

    cout << dp[n-1][n-1] << endl;

    return 0;
}

// dp[0] = 1;
// dp[i]  = dp[i-1] + dp[i-2]; 

/*
    int dp[n+1];
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        if (i -1 >= 0) {
            dp[i] += dp[i-1]
        }
        if (i-2 >= 0) {
            dp[i] += dp[i-2];
        }
    }
    cout << dp[n] << endl;

    int f0 = 1
    int f1 = 2
    for (int i = 2; i <= n; i++) {
        f3 = f0 + f1
        f0 = f1;
        f1 = f3
    }
    cout << f1

    bool dp[T+1];
    dp[0] = true;
    for (int i = 0; i < n; i++) {
        for (int w = 0; w <= T; w++) {
            if (w - a[i] >= 0) {
                dp[w] |= dp[w-a[i]]
            }
        } 
    }
    cout << dp[T] ? "true" : "false" << endl;

    or

    bool dp[n+1][T+1]
    dp[0][0] = true;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= T; j++) {
            dp[i][j] = dp[i-1][j];
            if (j - a[i] >= 0) {
                dp[i][j] |= dp[i-1][j-a[i]];
            }
        }
    }

    cout << dp[n][T] << endl;
*/  