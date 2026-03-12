#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) { 
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    k &= 1;
    vector<ll> L(n);
    for (int i = 0; i < n; i++) {
        L[i] = (i && L[i-1] > 0 ? L[i-1] : 0ll) + a[i];
    }

    vector<ll> R(n);
    for (int i = n-1 ; i >= 0; i--) {
        R[i] = (i + 1 < n && R[i+1] > 0 ? R[i+1] : 0ll) + a[i];
    }

    if (k == 0) {
        ll ans = *max_element(L.begin(), L.end());
        cout << ans << endl;
        return;
    } else {
        ll ans = LONG_MIN;
        for (int i = 0; i < n; i++) {
            ans = max(ans, L[i]+R[i]-a[i] + b[i]);
        }
        cout << ans << endl;
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