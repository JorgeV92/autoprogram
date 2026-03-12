#include <iostream>
#include <vector>

using namespace std; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (b <= d && c <= a+d-b) {
            cout << (d-b) + (a+d-b-c) << endl;
        } else {
            cout << -1 << endl;
        }        
    }
    return 0;
}