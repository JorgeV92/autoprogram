#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> prefixXOR(n+1);
    for (int i = 1; i <= n; i++) {
        if (i == r) {
            prefixXOR[i] = prefixXOR[l-1];
        } else {
            prefixXOR[i] = i;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << (prefixXOR[i+1] ^ prefixXOR[i]) << " \n"[i+1 == n];
    }
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