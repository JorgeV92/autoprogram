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
        ll n, k, x;
        cin >> n >> k >> x;
        if (2*x >= k*(k+1) && 2*x <= n*(n+1)-(n-k)*(n-k+1)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}