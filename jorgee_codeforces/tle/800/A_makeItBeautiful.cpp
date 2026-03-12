#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t{};
    cin >> t;
    while (t--) {
        int n{};
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        if (arr[0] == arr[n-1]) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            cout << arr[n-1] << " ";
            for (int i =0 ;i < n-1; i++) {
                cout << arr[i] << " \n"[i+1==n-1];
            }
        }
    }
    return 0;
}