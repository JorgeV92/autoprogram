#include <iostream>
#include <vector>

using namespace std;

#define ll long long 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n), b(n), c(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> c[i];
        }

        auto count_snowmen = [&](vector<ll>& X, vector<ll>& Y) {
            ll cnt = 0;
            for (int k = 0; k < n; k++) {
                bool valid = true;
                for (int i  = 0; i < n; i++) {
                    if (X[i] >= Y[(i+k)%n]) {
                        valid = false;
                        break;
                    }
                }
                if (valid) cnt++;
            }
            return cnt;
        };

        ll AB = count_snowmen(a, b);
        ll BC = count_snowmen(b, c);

        cout << AB * BC * n << endl;
    }
    return 0;   
}