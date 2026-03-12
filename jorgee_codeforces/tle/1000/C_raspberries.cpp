#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        ll prod = 1;
        for (int i = 0 ;i < n; i++) {
            cin >> a[i];
        }
        ll ans = 1e18;
        ll evens = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] % 2 ==0) evens++;
            if (a[i] % k == 0) ans = 0;
            ans = min(ans, k - a[i]%k);
        }
        if (k == 4) {
            if(evens >= 2) ans = min(ans, 0LL);
            else if (evens == 1) ans = min(ans, 1LL);
            else if (evens == 0) ans = min(ans, 2LL); 
        }
        cout << ans << '\n';

    }
    return 0;
}

