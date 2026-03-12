#include <iostream>
#include <vector>

using namespace std;

#define ll long long

ll divide(ll a, ll b) {
    return (a + b - 1) / b;
}

void solve() {
    ll x, y, k;
    cin >> x >> y >> k;
    ll a = k + k * y;
    ll ans = k + divide(a-1, x-1); 
    cout << ans << endl;
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