#include <iostream>
#include <vector>

using namespace std; 

vector<string> generateParenthesis(int n) {
    vector<string> allp;
    string tmp;

    auto dfs = [&](auto&& dfs, int op, int cl) {
        if (op == cl && op == n) {
            allp.push_back(tmp);
            return;
        }

        if (op < n) {
            tmp += '(';
            dfs(dfs, op+1, cl);
            tmp.pop_back();
        }

        if (cl < op) {
            tmp += ')';
            dfs(dfs, op, cl+1);
            tmp.pop_back();
        }
    };
    
    dfs(dfs, 0,0);
    return allp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}