#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int tt;;
    cin >> tt;
    while (tt--) {
        long long a, b;
        cin >> a >> b;
        if (a==b) {
            cout << 0 << ' ' << 0 << '\n';
        } else {
            long long g = abs(a-b);
            long long m = min(a%g, g-a%g);
            cout << g << " " << m << '\n';
        }
    }
    return 0;
}