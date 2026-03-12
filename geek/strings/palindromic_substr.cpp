#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

/*
    Given string str consisting of lowercase English alphabets, 
    the task is to find the total number of palindromic sub-strings 
    present in the sorted form of str.
*/

int countPalindrome(string s) {
    int n = s.size();
    int sum = 0;
    vector<int> count(26);
    for (int i = 0; i < n; i++) {
        count[s[i]-'a']++;
    }
    for(int i = 0; i < 26; i++) {
        if (count[i])
            sum += (count[i] * (count[i]+1) / 2);
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str = "ananananddd";
    cout << countPalindrome(str) << endl;

    return 0;
}