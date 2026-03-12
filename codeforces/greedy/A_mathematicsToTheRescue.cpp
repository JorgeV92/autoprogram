#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s;
    getline(cin, s);
    vector<char> a;
    for (int i = 0; i < s.size(); i++) {
        if (isdigit(s[i]))
            a.push_back(s[i]);
    }
    sort(a.begin(), a.end());
    string out = "";
    for (int i = 0; i < a.size(); i++) {
        if (i > 0)
            out += "+";
        out += a[i];
    }
    cout << out << '\n';
    return 0;
}