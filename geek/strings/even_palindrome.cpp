#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
    S is string containing only lowercase English alphabets. 
    We need to find if there exists at least one palindromic 
    sub-string whose length is even. 

*/

// Brute force 
// Time O(N^3)
// Space O(1)

bool hasEvenLengthPalindrome(string s) {
    
    auto is_palindrome = [&](string t) {
        int n = t.size();
        for (int i = 0; i < n/2; i++) {
            if (t[i] != s[n-i-1])
                return false;
        }
        return true;
    };

    int n = s.size();
    for (int i = 0; i < n; i++) {
        for (int len = 2; i + len <= n; len += 2) {
            if (is_palindrome(s.substr(i, len))) {
                return true;
            }
        }
    }
    return false;
} 

// Linear time solution 
// just check the middle two elements they must match 
// for an even length palindrome
bool check(string s) {
    for (int i = 0; i < s.size()-1; i++) {
        if (s[i] == s[i+1]) 
            return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s = "xzyyz";
    if (check(s)) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    return 0;
}