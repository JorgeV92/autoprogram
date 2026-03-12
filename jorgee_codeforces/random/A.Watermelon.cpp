#include <iostream>
#include <vector>

using namespace std; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int w;
    cin >> w;
    if (!(w & 1) && w != 2) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}