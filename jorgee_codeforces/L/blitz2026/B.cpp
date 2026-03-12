#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n > 26) {
        cout << "-1\n";
        return 0;
    }
    set<char> st;
    for (char c : s) st.insert(c);
    cout << n - (int)st.size() << "\n";
    return 0;
}