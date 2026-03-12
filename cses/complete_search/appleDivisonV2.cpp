#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>

using namespace std; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n{};
    cin >> n;
    using ll = long long;
    vector<ll> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    ll ans{INT64_MAX};
    for (int mask = 0 ; mask < (1<<n); mask++) {
        ll sum1{0};
        ll sum2{0};
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                sum1 += A[i];
            } else {
                sum2 += A[i];
            }
        }
        ans = min(ans, abs(sum1-sum2));
    }
    cout << ans << endl;

    return 0;
}