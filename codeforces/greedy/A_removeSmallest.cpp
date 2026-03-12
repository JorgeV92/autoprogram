#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0 ; i < n; i++) {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        for (int i = 1; i < n; i++) {
            if (abs(arr[i] - arr[i-1]) > 1) {
                cout << "NO\n";
                goto end;
            }
        }
        cout << "YES\n";
    end:;
    } 
    
    return 0;
}