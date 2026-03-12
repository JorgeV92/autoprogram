#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int ans = 0;
    int l = 0, r = n-1;
    while (l <= r) {
        if (l < r && arr[l] + arr[r] <= x ) {
            ans++;
            l++; r--;
        } else {
            ans++;
            r--;
        }
    }
    cout << ans << endl;
    return 0;
}