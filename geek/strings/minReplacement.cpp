#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
    Minimum replacements in a string to make adjacent characters unequal

    Given a lowercase character string str of size N. In one 
    operation any character can be changed into some other 
    character. The task is to find the minimum number of 
    operations such that no two adjacent characters are equal.
*/

void count_minimum(string s) {
    int n = s.length();
    int ans = 0;
    int i = 0;

    while (i < n) {
        int j = i;
        while (s[j] == s[i] && j < n) {
            j++;
        }
        int diff = j - i;
        ans += diff / 2;
        i = j;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str = "caaab"; 
    count_minimum(str);

    return 0;
}