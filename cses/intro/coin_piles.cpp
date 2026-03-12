#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int64_t a, b;
        cin >> a >> b;

        if ((2 * a - b)  % 3 == 0) {
            int64_t y = (2 * a - b) / 3;
            if (y >= 0 && (b - y) % 2 == 0) {
                int64_t x = (b-y) / 2;
                if (x >= 0) {
                    cout << "YES\n";
                    continue;
                }
            }
        }
        cout << "NO\n";
    }
    return 0;
}