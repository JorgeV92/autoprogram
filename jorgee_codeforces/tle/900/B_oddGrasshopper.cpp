#include <iostream>
#include <vector>

using namespace std;


using ll = long long;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int tt;
    cin >> tt;
    auto congruence = [&](int i, ll nn) -> ll {
        if (i ==0) return 0;
        if (i == 1) return nn;
        if (i == 2) return  -1;
        if (i == 3) return -nn-1;
        return -1;
    };
    while (tt--) {
        ll x, n;
        cin >> x >> n;
        ll d = congruence(n%4,n);
        if (x % 2 == 0) {
            cout << x - d << '\n';
        } else {
            cout << x + d << '\n';
        }
    }
    return 0;
}