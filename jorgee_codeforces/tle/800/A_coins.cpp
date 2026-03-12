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
        ll n, k;
        cin >> n >> k;
        bool valid = false;
        for (int x = 0; x < 2; x++) {
            if (((n - x*k) >= 0) && ((n-x*k) % 2 == 0)) {
                valid = true;
                break;
            }
        } 
        if (valid) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}