#include <iostream>
#include <vector>
#include <numeric>

using namespace std; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        bool valid = false;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (gcd(arr[i], arr[j]) <= 2) {
                    valid = true;
                } 
            }
        }

        if (valid) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}