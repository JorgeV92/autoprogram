#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std; 

#define ll long long 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> A(n);
    for (int i  =0 ; i < n; i++) {
        cin >> A[i];
    }

    vector<ll> L, R;

    auto subset = [&](int l, int r, vector<ll>& a) {
        int len = r - l + 1;
        for (int i = 0; i < (1 << len); i++) {
            ll sum = 0;
            for (int j = 0; j < len; j++) {
                if ((1 << j) & i)
                    sum = (sum + A[l+j]) % m;
            }
            a.push_back(sum);
        }
    };

    subset(0, n/2-1, L);
    subset(n/2, n-1, R);

    sort(L.begin(), L.end());
    ll ans = 0;
    for (ll r : R) {
        auto it = lower_bound(L.begin(), L.end(), m-r);
        if (it != L.begin()) {
            ll l = *prev(it);
            ans = max(ans, (l + r) % m);
        }
        ll lmax = L.back();
        ans = max(ans, (lmax + r) % m);
    }

    cout << ans << endl;

    return 0;
}