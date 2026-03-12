#include <iostream>
#include <vector>
#include <string>

using namespace std;

string longestPalindromeDP(string s) {
    int n = s.length();
    if (n == 0) return "";
    vector<vector<bool>> dp(n, vector<bool>(n));
    int start = 0, max_len = 1;
    for (int i = 0; i < n; i++) {
        dp[i][i] = true;
    }
    for (int i = 0; i < n-1; i++) {
        if (s[i] == s[i+1]) {
            dp[i][i+1] = true;
            start = i;
            max_len = 2;
        }
    }

    for (int len = 3; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len -1;
            if (s[i] == s[j] && dp[i+1][j-1]) {
                dp[i][j] = true;
                if (len > max_len) {
                    max_len = len;
                    start = i;
                }
            }
        }
    }

    return s.substr(start, max_len);
}

/**
 * Approach: Dynamic Programming
 * Time Complexity: O(N^2)
 * Space Complexity: O(N^2)
 */
string longestPalindromeDPGemini(string s) {
    int n = s.size();
    if (n == 0) return "";

    // dp[i][j] will be true if the string from index i to j is a palindrome
    vector<vector<bool>> dp(n, vector<bool>(n));

    int start = 0;
    int mxLen = 1;

    for (int i = 0; i < n; i++) {
        dp[i][i] = true;
    }
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;   
            if (s[i] == s[j]) {
                if (len == 2 || dp[i+1][j-1]) {
                    dp[i][j] = true;

                    if (len > mxLen) {
                        start = i;
                        mxLen = len;
                    }
                }
            }
        }
    }
    return s.substr(start, mxLen);
}

/**
 * Approach: Expand Around Center
 * Time Complexity: O(N^2)
 * Space Complexity: O(1)
 */
string longestPalindromeExpandCenter(string s) {
    int n = s.size();
    if (n == 0) return "";
    int start = 0;
    int maxLen = 1;

    auto expand = [&](int l, int r) {
        while (l >= 0 && r < n && s[l] == s[r]) {
            l--; r++;
        }
        int currentlen = r - l - 1;
        if (currentlen > maxLen) {
            maxLen = currentlen;
            start = l + 1;
        }
    };

    for (int i = 0; i < n; i++) {
        expand(i, i);
        expand(i, i+1);
    }
    return s.substr(start, maxLen);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}