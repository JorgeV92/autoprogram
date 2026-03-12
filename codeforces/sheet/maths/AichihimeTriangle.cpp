#include <iostream>
#include <vector>

using namespace std; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t{};
    cin >> t;
    while (t--) {
        int a{}, b{}, c{}, d{};
        cin >> a >> b >> c >> d;
        cout << b << ' '<< c << ' ' << c << '\n';
    }
    return 0;   
}