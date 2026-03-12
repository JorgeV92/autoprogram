#include <iostream>
#include <vector>
#include <numeric>

#define OUTT(...) std::cout << #__VA_ARGS__ << " = " << __VA_ARGS__ << '\n'
#define OUT(x, y) std::cout << x << ' ' << y << '\n';

using namespace std; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t{};
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        if (l*2>r) {
            OUT(-1,-1);
        }  else {
            OUT(l, l*2);
        }
    }
    return 0;
}