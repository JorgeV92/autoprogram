#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int sleep = 0;
    int mx = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            mx = max(mx, i + k);
        }  else {
            if (i >mx) {
                sleep++;
            }
        }
    }
    cout << sleep << endl;
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