#include <iostream>
#include <vector>
#include <string>
#include <string_view>
#include <algorithm>

using namespace std;

string prefix_function(const string& pat) {
    string a = pat;
    reverse(a.begin(), a.end());
    a = pat + '$' + a;
    int n = a.size();
    vector<int> lps(n, 0);
    int len = 0;
    int i = 1;
    while (i < n) {
        if (a[i] == a[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len-1];
            } else {
                lps[i]  = 0;
                i++;
            }
        }
    }
    return a.substr(0, lps.back());
}

void solve() {
    string s;
    cin >> s;
    int l= 0;
    while (l < (int)s.size() - l - 1) {
        if (s[l] != s[(int)s.size() - l - 1])  
            break;
        l++;
    }
    if (l > 0) {
        cout << s.substr(0, l);
    }

    if ((int)s.size() > 2 * l) {
        string t = s.substr(l, (int)s.size() - 2 * l);
        string a = prefix_function(t);
        reverse(t.begin(), t.end());
        string b = prefix_function(t);
        if ((int)a.size() < (int)b.size()) {
            swap(a, b);
        }
        cout << a;
    }

    if (l > 0) {
        cout << s.substr((int)s.size() - l, l);
    }
    cout << '\n';
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