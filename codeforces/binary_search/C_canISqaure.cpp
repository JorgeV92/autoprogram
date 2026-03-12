#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            sum += x;
        }
        auto is_sqaure = [&](ll t) {
            ll l = 1, r = 1e9;
            while (l <= r) {
                ll m = l + (r-l) / 2;
                if (m*m > t) {
                    r = m-1;
                }  else if (m*m < t) {
                    l = m+1; 
                } else {
                    return true;
                }
            }
            return false;
        };
        cout << (is_sqaure(sum) ? "YES\n" : "NO\n");
    }
    return 0;
}