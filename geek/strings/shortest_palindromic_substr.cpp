#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
    Shortest Palindromic Substring
*/

/*
    Given a string you need to find the shortest palindromic substring of the string. 
    If there are multiple answers output the lexicographically smallest.
*/

// O(n^2) Time
// O(n^2) Space
string shortestPalindrome(string s) {
    int n = s.size();
    vector<string> strs;

    for (int i = 0; i < n; i++) {
        int l = i;
        int r = i;
        string odd = "";
        string even = "";

        // odd
        while (l >= 0 && r < n && s[l] == s[r]) {
            odd += s[l];
            l--; r++;
        }

        l = i-1;
        r = i;

        // even
        while (l >= 0 && r < n && s[l] == s[r]) {
            even += s[l];
            l--; r++;
        }
        strs.push_back(odd);
        strs.push_back(even);
    }

    string ans = strs[0];
    for (int i = 1; i < strs.size(); i++) {
        if (strs[i] != "") {
            ans = min(ans, strs[i]);
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

     string s = "geeksforgeeks";
    cout << shortestPalindrome(s) << endl;

    return 0;
}