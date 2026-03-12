#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>


using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }

        ll ans = 0;
        for (int i = 0; i < m; i++) {
            ll sum = 0;
            vector<ll> tmp;
            for (int j = 0; j < n; j++) {
                tmp.push_back(a[j][i]);
                sum += a[j][i];
            } 
            ll cur = 0;
            sort(tmp.begin(), tmp.end());
            for (int k = 0; k < n; k++) {
                cur += tmp[k];
                ans += (ll)abs((sum - cur) - (n-1-k) * tmp[k]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}