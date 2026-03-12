#include <iostream>
#include <vector>

using namespace std;

#define ll long long

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
        sort(arr.begin(), arr.end());
        ll ans =0;
        for (int i = 0; i < n; i++) {
            ans += (arr[i]-i>0?arr[i]-i:0);
        }
        cout << ans << endl;
    }
    return 0;
}