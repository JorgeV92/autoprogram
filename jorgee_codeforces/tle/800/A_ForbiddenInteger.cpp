#include <iostream>
#include <vector>

using namespace std; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k, x;
        cin >> n >> k >> x;
        if (x != 1) {
            cout << "YES\n";
            cout << n << endl;
            for (int i = 0; i < n; i++) {
                cout << 1 << " \n"[i+1==n];
            }
        } else if (k == 1 || (k == 2 && (n&1))) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            cout << n / 2 << endl;
            if ((n&1)) {
                cout << 3 << " ";
            } else {
                cout << 2 << " ";
            }
            for (int i = 0; i < (n/2)-1; i++) {
                cout << 2 << " ";
            }
            cout << endl;
        }
    }
    return 0;
}