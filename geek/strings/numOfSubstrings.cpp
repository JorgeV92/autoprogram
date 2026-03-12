#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
    Suppose we are given a string s1, we need to the find total number of 
    substring(including multiple occurrences of the same substring) of s1 
    which are present in string s2.
    
    Time O(n^3) 
    Space O(n)
*/

void countSubstrs(string s1, string s2) {
    int ans = 0;
    for (int i = 0; i < s1.size(); i++) {
        string s3;
        for (int j = i; j < s1.size();j++) {
            s3 += s1[j];

            if (s2.find(s3) != string::npos) {
                ans++;
            }
         }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1 = "aab", s2 = "aaaab";
    countSubstrs(s1, s2);

    return 0;    
}