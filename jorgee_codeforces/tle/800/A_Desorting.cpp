#include <iostream>
#include <vector>
#include <algorithm>

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
        int diff = 1e9;
        bool sorted = true;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            if (i > 0) {
                diff = min(diff, arr[i] - arr[i-1]);
                sorted &= arr[i] >= arr[i-1];
            } 
        }
        if (!sorted) {
            cout << 0 << endl;
        } else {
            cout << diff / 2 + 1 << endl;
        }

    }
    return 0;  
}