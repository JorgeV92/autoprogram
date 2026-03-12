#include <iostream>
#include <vector>
#include <string>

using namespace std;

string reverseString(string s, int L, int R) {
    if (L < 0 || R >= s.size() || L > R) 
        return s;
    
    while (L < R) {
        swap(s[L++], s[R--]);
    }
    return s;
}

// O(n^2) time
/// O(n) space
string reverseParentheses(string s) {
    int n = s.size();   
    stack<int> st;
    
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            st.push(i);
        } else if (s[i] == ')') {
            reverse(s.begin() + st.top() + 1, s.begin() + i);
            st.pop();
        }
        
    }

    string res = "";
    for (int i = 0; i < n; i++) {
        if (s[i] != ')' && s[i] != '(') 
            res += s[i];
    }
    return res;
}

string reverseParentheses2(string s) {
    int n = s.size();
    int start, end;

    auto reverse_str = [&](string t, int s, int e) -> string {
        reverse(t.begin() + s, t.begin() + e+1);
        return t;
    };

    while (true) {
        end = s.find(')', 0); 
        if (end == string::npos) {
            break;
        }

        start = s.rfind('(', end);
        s = reverse_str(s, start+1, end-1);
        s.erase(start, 1);
        s.erase(end-1, 1);
    }
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str = "(skeeg(for)skeeg)";

    cout << reverseParentheses2(str) << endl;

    return 0;
}