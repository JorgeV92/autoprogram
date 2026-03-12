#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
    Given a string str, and two integers L and R, the task is 
    to reverse the string in the range [L, R] i.e. str[L...R].
*/

string reverseString(string s, int l, int r) {
    string t;
    for (int i = l; i <= r; i++) {
        t += s[r-i + 1];
    }
    return s.substr(0, l) + t + s.substr(r+1);
}

string reverseString2(string s, int l, int r) {
    if (l < 0 || r >= s.size() || l > r) 
        return s;
    while (l < r) {
        swap(s[l++], s[r--]);
    }
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s = "geeksforgeeks";
    int L = 5, R = 7;
    cout << reverseString2(s, L, R) << endl;
    
    return 0;
}