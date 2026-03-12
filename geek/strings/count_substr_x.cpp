#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
    Given a string 'S' (composed of digits) and an integer 'X", the task is to 
    count all the sub-strings of 'S' that satisfy the following conditions:  

    The sub-string must not begin with the digit '0'.
    And the numeric number it represents must be greater than 'X'.

*/

// O(n^3) time 
// O(1) space
int count(string t, int x) {
    int count = 0;
    const int n = t.size();
    for (int i = 0; i < n; i++) { // O(n)
        if (t[i] != '0') {
            for (int len = 1; (i + len) <= n; len++) { // O(n)
                if (stoi(t.substr(i, len)) > x)  // O(n)
                    count++;
            }
        }
    }       // -> O(n^3)
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S = "2222";
    int X = 97;
    cout << count(S, X) << endl;

    return 0;
}