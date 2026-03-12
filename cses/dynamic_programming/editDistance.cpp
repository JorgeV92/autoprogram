#include <iostream>
#include <vector>
#include <string>

using namespace std;

constexpr int inf = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t;
    cin >> s >> t;

    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, inf));

    dp[0][0] = 0;
    for (int i = 0; i <=n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i != 0) 
                dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
                
            if (j != 0) 
                dp[i][j] = min(dp[i][j], dp[i][j-1] + 1);

            if (i != 0 && j != 0) {
                dp[i][j] = min(
                    dp[i][j],
                    dp[i-1][j-1] + (s[i-1] != t[j-1])
                );
            }
        }
    }

    cout << dp[n][m] << endl;

    return 0;
}