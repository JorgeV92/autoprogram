#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*
    Permutation of given string that maximizes count of Palindromic substrings

    Given a string S, the task is to find the permutation of the string such that 
    palindromic substrings in the string are maximum.
*/

void maxPalindromicSubstring(string& s) {
    sort(s.begin(), s.end());
    cout << s << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s = "abcb";
    maxPalindromicSubstring(s);
    return 0;
}   