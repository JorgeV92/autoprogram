#include <iostream>
#include <vector>

using namespace std; 

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int tt;;
    cin >> tt;
    while (tt--) {
        long long n, k;
        cin >> n >> k;
        vector<long long> a(n*k+1);
        for (int i = 1; i <= n*k; i++) 
            cin >> a[i];
        long long x = (n+1) / 2 - 1;
        x = n - x;
        long long z = n*k+1;
        long long ans = 0;
        while (k--) {
            z -= x;
            if (z <= 0) break;
            ans += a[z];
        }
        cout << ans << '\n';
    }
    return 0;   
}