#include <iostream>
#include <vector>

using namespace std; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    using ll = long long;
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        int x = 1;
        while (n % x == 0) {
            x++;
        }
        cout << x-1 << endl;
    }
    return 0;
}