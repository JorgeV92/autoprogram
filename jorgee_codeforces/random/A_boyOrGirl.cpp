#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    set<char> st(s.begin(), s.end());

    if ((int)st.size() & 1) {
        cout << "IGNORE HIM!\n";
    } else {
        cout << "CHAT WITH HER!\n";
    }

    return 0;
}