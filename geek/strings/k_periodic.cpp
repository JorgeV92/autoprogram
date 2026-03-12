#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
    Given a string str and an integer K, the task is to 
    check whether the given string is K-periodic. A string 
    is k-periodic if the string is a repetition of the 
    sub-string str[0 ... k-1] i.e. the string "ababab" is 2-periodic. 
    Print Yes if the given string is k-periodic, else print No.

*/

// O(K * log(len)) time
// O(1) space
bool isKPeriodic(string s, int k) {

    auto is_prefix = [](string t, int len, int i, int k) {
        if (i + k > len) {
            return false;
        } 
        for (int j = 0; j < k; j++) {
            if (t[i] != t[j]) 
                return false;
            i++;
        }
        return true;
    };

    int n = s.size();
    for (int i = k; i < n; i += k) {
        if (!is_prefix(s, n, i, k))
            return false;
     }
     return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str = "geeksgeeks";
    int k = 5;

    if (isKPeriodic(str, k))
        cout << ("Yes");
    else
        cout << ("No");
    cout << endl;
    return 0;
}