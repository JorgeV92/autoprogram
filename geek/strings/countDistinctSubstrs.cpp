#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std; 

/*
    Count of Distinct Substrings occurring consecutively in a given String

    Given a string str, the task is to find the number of distinct substrings that are placed consecutively in the given string.

*/

// O(n^2) Time
// O(n^2) Space
void distinctSimilarSubstrings(string s) {
    int n = s.size();
    if (n <= 1) {
        cout << 0 << endl;
        return;
    }

    vector<vector<int>> dp(n+1, vector<int>(n+1));
    unordered_set<string> substrs;

    for (int j = n-1; j >= 0; j--) {
        for (int i = j-1; i >= 0; i--) {
            if (s[i] == s[j]) {
                dp[i][j] = dp[i+1][j+1] + 1;
            } else {
                dp[i][j] = 0;
            }

            if (dp[i][j] >= j-i) {
                substrs.insert(s.substr(i, j-i));
            }
        }
    }
    cout << substrs.size() << endl;
}

// O(N^2) Time
// O(N) Space
void distinctSimilarSubstringsOpt(string  s) {
    int n = s.size();
    if (n <= 1) {
        cout << 0 << endl;
        return;
    }
    vector<int> dp(n+1);

    unordered_set<string> subtrs;
    for (int j = n-1; j >= 0; j--) {
        vector<int> new_dp(n+1);
        for (int i = j-1; i >= 0; i--) { 
            if (s[i] == s[j]) {
                new_dp[i] = dp[i+1] + 1; 
            } else{
                new_dp[i] = 0;
            }

            if (dp[i] >= j-i) {
                subtrs.insert(s.substr(i, j-i));
            }
        }
        dp = new_dp;
    }
    cout << subtrs.size() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
     string str = "geeksgeeksforgeeks";

    distinctSimilarSubstringsOpt(str);
    return 0;
}