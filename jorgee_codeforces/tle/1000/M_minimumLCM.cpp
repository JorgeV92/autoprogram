#include <iostream>
#include <vector>

using namespace std; 

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a = 1;
        for (int g = 2; g * g <= n; g++) {
            if (n % g == 0) {
                a = n / g;
                break;
            }
        }
        cout << a << ' ' << n - a << '\n';
    }
    return 0;
}