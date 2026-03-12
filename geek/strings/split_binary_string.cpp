#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

/*
    Given a binary string str of length N, the task is to find the maximum 
    count of consecutive substrings str can be divided into such that all 
    the substrings are balanced i.e. they have equal number of 0s and 1s. 
    If it is not possible to split str satisfying the conditions then print -1.
*/

// O(n) time
// O(1) space 
int maxSubstr(string s) {
    int n = s.size();
    int zeros = 0 , ones = 0;
    int total = 0;
    for (int i= 0; i < n; i++) {
        if (s[i] == '0') {
            zeros++;
        } else {
            ones++;
        }
        if (zeros == ones) total++;
    }
    return (zeros == ones ? total : -1);
}


int maxSubstrStack(string s) {
    int total = 0;
    int i = 0;
    stack<int> st;
    st.push(s[i++]);
    while (i < s.size()) {
        while (i < s.size() && st.size() && (st.top() != s[i])){
            st.pop();
            i++;
        }
        if (st.empty()) {
            total++;
        }
        while (i < s.size() && (st.empty() || st.top() == s[i])) {
            st.push(s[i++]); 
        }   
    }
    if (st.empty()) 
        return total;
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str = "0100110101";

    cout << maxSubstrStack(str) << endl;

    return 0;
}