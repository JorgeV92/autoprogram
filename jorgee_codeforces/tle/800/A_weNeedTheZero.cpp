#include <iostream>
#include <vector>

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
        int x = 0;
        for (int y : arr) {
            x ^= y;
        }
        if ((n&1)) {
            cout << x << endl;
        } else {
            if (x == 0) {
                cout << x << endl;
            } else {
                cout << -1 << endl;
            }
        }
    }
    return 0;
}