#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--){
        int n{};
        cin >> n;
        vector<int> arr(n);
        for (int& x : arr) {
            cin >> x;
        }
        int len = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) {
                len++;
            }  else {
                ans = max(ans, len);
                len = 0;
            }
        }
        cout << max(ans, len) << endl;
    }

    return 0;
}