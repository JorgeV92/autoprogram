#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/**
 * Approach: Iterative Stack
 * Time Complexity: O(MaxK * N) - effectively proportional to output length
 * Space Complexity: O(N) - depth of nesting
 */
string decodeStringStack(string s) {
    stack<int> counts;
    stack<string> words;
    string ans = "";
    int k = 0;
    for (char c : s) {
        if (isdigit(c)) {
            k = k * 10 + (c - '0');
        } else if (c == '[') {
            counts.push(k);
            words.push(ans);
            k = 0;
            ans = "";
        } else if (c == ']') {
            string tmp = words.top();
            words.pop();
            int re = counts.top();
            counts.pop();
            while (re--) {
                tmp += ans;
            }
            ans = tmp;
        } else {
            ans += c;
        }
    } 
    return ans;
}

/**
 * Approach: Recursion / DFS
 * Time Complexity: O(Output Size)
 * Space Complexity: O(N) - recursion stack
 */
string decodeStringDFS(string s) {
    int i = 0; 
    return dfs(s, i);
}

string dfs(const string& s, int& i) {
    string res = "";
    int k =0;

    while (i < s.length()) {
        if (isdigit(s[i])) {
            k = k * 10 + (s[i] - '0');
        } else if (s[i] == '[') {
            i++;
            string inner = dfs(s, i);
            while (k > 0) {
                res += inner;
                k--;
            }
        } else if (s[i] == ']') {
            return res;
        } else {
            res += s[i];
        }
        i++;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    return 0;
}