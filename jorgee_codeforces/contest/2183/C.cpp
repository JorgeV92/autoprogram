#include <iostream>
#include <vector>

using namespace std; 

#define ll long long

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    ll ans = 0;
    for (int i = 0; i <= k-1; i++) {
        ll left = m-i*2+1;
        if (left < 0) continue;
        ll T = i+1;
        ll right = (m -i + 1) / 2;
        right = min(right, left);
        right = min(right, n-k);
        T += right;
        ans = max(ans, T);
    }
    cout << ans << '\n';
}

int main( ){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}


