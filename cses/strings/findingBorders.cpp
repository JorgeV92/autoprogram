#include <iostream>
#include <vector>
#include <string>
#include <string_view>
#include <set>

using namespace std;

vector<int> z_function(string_view s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i < r) {
            z[i] = min(r-i, z[i-l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i+z[i]])
            z[i]++;
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();
    
    vector<int> z = z_function(s);
    for (int i  = n-1; i > 0; i--) {
        if (i + z[i] == n) {
            cout << z[i] << " ";
        }
    }
    cout << '\n';
    return 0;
}