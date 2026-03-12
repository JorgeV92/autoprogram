#include <iostream>
#include <vector>
#include <string>
#include <string_view>

using namespace std; 

#define OUT(x) cout << x << '\n';

// Longest Palindromic Subsequence 

vector<vector<int>> memo;

int lps(string_view s, int l, int r) {
    if (l > r) 
        return 0;
    if (l == r) 
        return 1;
    if (memo[l][r] != -1) return memo[l][r];
    if (s[l] == s[r])
        return memo[l][r] = lps(s, l+1, r-1) + 2;
    return memo[l][r] = max(lps(s,l+1,r), lps(s,l,r-1));
}

int longestPalinSubseq(string &s) {
    memo = vector<vector<int>>(s.size(), vector<int>(s.size(),-1));
    return lps(s, 0, s.size() - 1);
}

int lpsTabulation(string_view s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n));
    for (int i = n-1; i >= 0; i--) {
        for (int j = i; j < n; j++) {
            if (i == j) {
                dp[i][j] = 1;
                continue;
            }
            if (s[i] == s[j]) {
                if (i + 1 == j) {
                    dp[i][j] = 2;
                } else {
                    dp[i][j] = dp[i+1][j-1] + 2;
                }
            } else {
                dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
            }
        } 
    }

    return dp[0][n-1];
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s = "bbabcbcab";
    OUT(longestPalinSubseq(s));

    OUT(lpsTabulation(s));

    return 0;
}