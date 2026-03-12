#include <iostream>
#include <vector>

using namespace std; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        int x = ((c&1) ? c/2+1 : c/2);
        int y = c - x;
        if (a+x > b+y) {
            cout << "First\n";
        } else {
            cout << "Second\n";
        } 
    } 
    return 0;
}