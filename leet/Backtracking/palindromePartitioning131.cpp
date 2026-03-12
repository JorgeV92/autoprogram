#include <iostream>
#include <vector>
#include <string>

using namespace std;

 vector<vector<string>> partition(string s) {
    int n = s.size();
    vector<vector<string>> alls;
    vector<string> p;

    auto is_pal = [&](int l, int r) {
        while (l < r ){
            if (s[l] != s[r]) {
                return false;
            }
            l++; r--;
        }
        return true;
    };

    auto dfs = [&](auto&&dfs, int i) {
        if (i == s.length()) {
            alls.push_back(p);
            return;
        }

        for (int j= i; j < n; j++) {
            if (is_pal(i, j)) {
                p.push_back(s.substr(i, j-i+1));
                dfs(dfs, j+1);
                p.pop_back();
            }
        }
    };

    dfs(dfs, 0);
    return alls;
 }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}