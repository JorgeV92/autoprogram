#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s{};
    cin >> s;
    int n = s.size();
    vector<string> out{};
    string path{};
    vector<int> count(26);
    for (int i = 0; i < n; i++) {
        count[s[i]-'a']++;
    }

    auto dfs = [&](auto&& dfs) {
        if (path.size() == n) {
            out.push_back(path);
            return;
        }
        for (int i = 0; i < 26; i++) {
            if (count[i] > 0) {
                count[i]--;
                path += (char(i+'a'));
                dfs(dfs);
                path.pop_back();
                count[i]++;
            }
        }
    };

    dfs(dfs);
    cout << out.size() << endl;
    for (const string& x : out) {
        cout << x << endl;
    }

    return 0;   
}
