#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        auto sgn = [&](int x) {
            if (x > 0) return 1;
            else return -1;
        };
        int64_t sum = 0;
        for (int i = 0; i < n; i++) {
            int curr = arr[i];
            int j = i;
            while (j < n && sgn(arr[i]) == sgn(arr[j])) {
                curr = max(curr, arr[j]);
                j++;
            }
            sum += curr;
            i = j -1;
        }
        cout << sum << "\n";
    }
    return 0;
}