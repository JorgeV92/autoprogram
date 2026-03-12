#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std; 

string infixToPostfix(string& s) {

    auto pred = [&](char c) {
        if (c == '^') {
            return 3;
        } else if (c == '*' || c == '/') {
            return 2;
        } else if (c == '+' || c == '-') {
            return 1;
        }
        return -1;
    };

    string res;
    stack<char> st;
    for (int i = 0; i < s.length(); i++) {
        int c = s[i];
        if (isalpha(c) || isdigit(c)) {
            res += c;
        } else if (c == '(') {
            st.push(c);
        } else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                res += st.top();
                st.pop();
            } 
            st.pop();
        } else {
            while (!st.empty() && st.top() != '(' 
                    && (pred(st.top()) > pred(c) 
                    || (pred(st.top()) == pred(c) 
                    && !(c == '^')))) {
                res += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}   