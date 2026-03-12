#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t{};
    cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;
        if (a+b+2 <= n || (a==b && b == n)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}