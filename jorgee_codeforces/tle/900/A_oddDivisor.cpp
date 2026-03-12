#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        long long n;
        cin >> n;
        if (n & (n-1)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}