#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k, q;
        cin >> n >> k >> q;
        vector<int> a(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }        
        long long total = 0;
        int suf = 0;
        for (auto x : a) {
            suf = x <= q ? suf + 1 : 0;
            total += max(0, suf - k + 1);
        }
        cout << total << "\n";
        
    }
    return 0;
}