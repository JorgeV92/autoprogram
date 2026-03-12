#include <iostream>
#include <vector>
#include <string>

using namespace std;

int lcsRec(string& s1, string& s2, int m, int n) {
    if (m == 0 || n == 0)
        return 0;
    if (s1[m-1] == s2[n-1])
        return 1 + lcsRec(s1, s2, m-1,n-1);
    else   
        return max(lcsRec(s1, s2, m, n-1), lcsRec(s1, s2, m-1, n));
}

int lcsR(string& s1, string& s2) {
    int m = s1.size();
    int n = s2.size();
    return lcsRec(s1, s2, m, n);
}

int lcsTopDown(string& s1, string& s2, int m, int n, vector<vector<int>>& memo) {
    if (m == 0 || n == 0) return 0;
    if (memo[m][n] != -1)
        return memo[m][n] ;
    if (s1[m-1] == s2[n-1]) 
        return memo[m][n] = 1 + lcsTopDown(s1, s2, m-1,n-1,memo);
    else    
        return memo[m][n] = max(lcsTopDown(s1, s2, m,n-1, memo), lcsTopDown(s1, s2, m-1, n-1, memo));
}

int lcsTD(string& s1, string& s2) {
    int m = s1.size();
    int n = s2.size();
    vector<vector<int>> memo(m+1, vector<int>(n+1, -1));
    return lcsTopDown(s1, s2, m, n, memo);
}

int lcsBottomUp(string& s1, string& s2) {
    int m = s1.size(), n = s2.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i-1] == s2[j-1]) 
                dp[i][j] = dp[i-1][j-1] + 1;
            else 
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[m][n];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";
    int m = s1.size();
    int n = s2.size();

    cout << lcsBottomUp(s1, s2) << endl;
    return 0;   
}