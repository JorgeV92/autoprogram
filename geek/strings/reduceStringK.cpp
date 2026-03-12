#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std; 

/*
    Reduce the string by removing K consecutive identical 
    characters.

    Given a string str and an integer k, the task is to reduce the string by 
    applying the following operation any number of times unitl it is no longer 
    possible.

    Choose a group of k consecutive identical characters and remove them from 
    the string.

    print the stirng
*/

string removeKChars(int k, string s) {
    if (k == 1) return "";
    string ans = "";
    using P = pair<char, int>;
    stack<P> stk;
    for (int i = 0; i < (int)s.size(); i++) {
        if (stk.empty()) {
            stk.push({s[i], 1});
        } else {
            if (s[i] == stk.top().first) {
                P p = stk.top();
                stk.pop();
                p.second++;
                if (p.second < k) 
                    stk.push(p);
            } else {
                stk.push(make_pair(s[i], 1));
            }
        }
    }

    while (!stk.empty()) {
        if (stk.top().second > 1) {
            int cnt = stk.top().second;
            while (cnt--) 
                ans += stk.top().first;
        } else {
            ans += stk.top().first;
        }
        stk.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s = "geeksforgeeks";
    int k = 2;
    cout << removeKChars(k, s) << "\n";
    return 0;
}