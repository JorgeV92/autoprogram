/*
    So here is the many ways to program the Longest Common Subsequence.
*/
#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

// assume 1 <= a.length, b.length <= 1000
void arrayLCS(string a, string b) {
    // Time complexity O(N * M) where N is the size of string 1 and M the size of 
    // string two
    // Space is also O(N*M) to store out dp table 
    // dp[i][j] = length of LCS of prefixes A[0..i-1], B[0..j-1] 
    int dp[1001][1001];
    memset(dp , 0, sizeof(dp));
    for (int i = 0; i <= a.size(); i++) {
        for (int j = 0; j <= b.size(); j++) {
            // PULL DP
            if (i == 0 || j == 0) {
                continue;
            }
            if (a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    cout << dp[a.size()][b.size()] << endl;

    string ans;
    int i = a.size(), j = b.size();
    while (i > 0 && j > 0) {
        if (a[i-1] == b[j-1]) {
            ans.push_back(a[i-1]);
            i--;
            j--;
        } else if (dp[i-1][j] > dp[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }

    auto reverseString = [](string s) -> string {
        string ans = s;
        int u = 0;
        int v = s.size()-1;
        while (u < v) {
            swap(ans[u], ans[v]);
            u++;
            v--;
        }
        return ans;
    };

    string res = reverseString(ans);

    cout << res << endl;
}

void vectorLCS(string a, string b) {
    vector<vector<int>> dp(a.size()+1, vector<int>(b.size() + 1));
    for (int i = 0; i <= (int)a.size(); i++) {
        for (int j = 0; j <= (int)b.size(); j++) {
            if (i == 0 || j == 0) {
                continue;
            }
            if (a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    cout << dp[a.size()][b.size()] << endl;

    string ans;
    int i = a.size(), j = b.size();
    while (i > 0 && j > 0) {
        if (a[i-1] == b[j-1]) {
            ans.push_back(a[i-1]);
            i--; j--;
        } else  if (dp[i-1][j] > dp[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }

    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}

int main() {
    string a = "abcde";
    string b = "ace";

    // arrayLCS(a, b);
    vectorLCS(a, b);

    return 0;
}



