#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

using ll = long long;

void solve() {
    int n, p;
    cin >> n >> p;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0 ;i < n; i++) {
        cin >> b[i];
    }
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) {
        return b[i] < b[j];
    });
    ll ans = p;
    int k = n-1;
    for (auto i : ord) {
        while (k > 0 && a[i] > 0) {
            a[i]--, k--;
            ans += min(p, b[i]);
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}