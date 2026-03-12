#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        ll n, x;
        cin >> n >> x;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        ll mn = 0, mx = 0;
        for (int i = 0; i < n; i++) {
            mn += a[i];
            mx += (a[i] + x-1) / x;
        }
        mn = (mn + x-1) / x;
        cout << mn << ' ' << mx << '\n';
    }
    return 0;
}