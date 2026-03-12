#include <iostream>
#include <vector>

using namespace std; 


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    using ll = long long;

    ll n;
    cin >> n;

    while (n != 1) {
        cout << n << " ";
        if (!(n & 1)) {
            n >>= 1;
        } else {
            n = n * 3 + 1;
        }
    }   
    cout << n <<  " ";

    return 0;
}
