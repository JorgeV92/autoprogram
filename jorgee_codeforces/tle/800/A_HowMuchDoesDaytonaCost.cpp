#include <iostream>
#include <vector>

using namespace std; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        bool found = false;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x == k){
                found = true;
            }   
        }
        if (found) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}