#include <iostream>
#include <vector>
#include <string>

using namespace std; 

void solve() {
    int n;
    cin >> n;
    vector<string> strs(n);
    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }
    string s = strs[0];


    for (int i = 1; i < n; i++) {
        string prev = strs[i] + s;
        string after = s + strs[i];
        if (prev < after) {
            s = prev;
        } else {
            s = after;
        }
    }

    cout << s << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
    return 0;
}
