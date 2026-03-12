#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    vector<int> A(n), B(n);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> B[i];
     }


    // dp[i][j] - is the lonegst common subsequence from A[0..i-1] and B[0..j-1] 
    vector<vector<int>> dp(n+1, vector<int>(n+1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (A[i-1] == B[j-1]) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]); 
            }
        }       
    }

    cout << dp[n][n] << endl;

    return 0;
}
