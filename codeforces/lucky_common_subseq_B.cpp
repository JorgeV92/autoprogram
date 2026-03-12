#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    // Given two string S and T find all occurrences of T in S.
    // Naive string matching 
    // O(n * m) time 
    // Finds the first occurrence index of the string T in S.
    auto string_match = [](const string& s, const string& t) -> int {
        int n = s.size();
        int m = t.size();

        for (int i = 0; i + m - 1 < n; i++) {
            bool found = true;
            for (int j = 0; j < m; j++) {
                if (s[i+j] != t[j]) {
                    found = false;
                    break;
                }
            }
            if (found) {
                return i;
            }
        }

        return -1;
    };

    auto compute_pi = [](const string& t) -> vector<int> {
        int n = t.size();
        vector<int> pi(n);
        for (int i = 1; i < n; i++) {
            int j = pi[i-1];
            while (j > 0 && t[i] != t[j]) {
                j = pi[j-1];
            }
            if (t[i] == t[j]) {
                j++;
            }
            pi[i] = j;
        }
        return pi;
    };

    auto string_match_with_pi = [&](const string& s, const string& t ) -> int {
        int n = s.size();
        int m = t.size();
        vector<int> pi = compute_pi(t);
        for (int i = 0, j = 0; i < n;) {
            if (s[i] == t[j]) {
                i++; j++;
                if (j == m) {
                    return i - m;
                }
            } else if (j > 0) {
                j = pi[j-1];
            } else {
                i++;
            }
        }
        return -1;
    };

    // String Matching Test
    string s = "cabcababacaba";
    string t = "aba";
    // cout << string_match(s, t) << endl;

    string a = "abcabcd";
    auto pi = compute_pi(a);
    for (int x : pi) {
        cout << x << " ";
    }
    cout << endl;
    cout << string_match_with_pi(s, t) << endl;
    return 0;


    string s1, s2, virus;
    cin >> s1 >> s2 >> virus;

    vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1));
    for (int i = 0; i <= (int)s1.size(); i++) {
        for (int j = 0; j <= (int)s2.size(); j++) {
            if (i == 0 || j == 0) {
                continue;
            }
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    cout << dp[s1.size()][s2.size()] << endl;


    string ans;
    int i = s1.size(), j = s2.size();
    while (i > 0 && j > 0) {
        if (s1[i-1] == s2[j-1]) {
            ans.push_back(s1[i-1]);
            i--; j--;
        } else if (dp[i-1][j] > dp[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;

    return 0;
}