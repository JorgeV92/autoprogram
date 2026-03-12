#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t{};
    cin >> t;
    while (t--) {
        int n; 
        cin >> n;
        using ll = long long;
        for (int i = 0; i < n; i++) {
            ll x;
            cin >> x;
            cout << n+1 - x << " \n"[i+1==n];
        }
    }

    return 0;
}