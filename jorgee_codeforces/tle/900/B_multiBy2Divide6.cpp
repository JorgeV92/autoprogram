#include <iostream>
#include <vector>

using namespace std; 

using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        ll n;
        cin >> n;
        int cnt2 = 0, cnt3 = 0;
        while (n % 2 == 0) {
            n /= 2;
            cnt2++;
        } 
        while (n % 3 == 0) {
            n /= 3;
            cnt3++;
        }
        if (n == 1 && cnt2 <= cnt3) {
            cout << 2 * cnt3 - cnt2 << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
    return 0;
}   