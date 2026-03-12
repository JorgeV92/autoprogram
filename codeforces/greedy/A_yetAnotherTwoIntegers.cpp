#include <iostream>
#include <vector>

using namespace std; 

using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {  
        ll a, b;
        cin >> a >> b;
        ll d = abs(a-b);
        cout << (d + 10 - 1) / 10 << '\n';
    }
    return 0;   
}