#include <iostream>
#include <vector>

using namespace std; 

void solve() {
    int n, k;
    cin >> n >> k;
    // for (int i = 1; i <= n; i++ ){
    //     if (i * (n-i) <= k) {
    //         cout << i << endl;
    //         break;
    //     }
    // }

    if (k >= n-1) {
        cout << 1 << endl;
    } else {
        cout << n << endl;
    }
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