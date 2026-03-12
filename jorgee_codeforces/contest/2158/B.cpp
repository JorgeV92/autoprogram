#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void solve() {
    int n;
    cin >> n;
    if ((n*2) & 1) {
        cout << 0 << endl;
        return;
    }
    vector<int> arr(2*n);
    for (int i = 0; i < 2*n; i++) {
        cin >> arr[i];
    }

    unordered_map<int,int> frq;
    for (int i =0; i < arr.size(); i++) {
        frq[arr[i]]++;
    } 

    int cnt_odd = 0;
    int cnt_even = 0;

    for (auto& [val, count] : frq) {
        if (count == 0) continue;
        if (count % 2 != 0) {
            cnt_odd++;
        } else {
            cnt_even++;
        }
    } 

    int ans = cnt_odd + (2 * cnt_even);
    if (cnt_odd == 0) {
        if (cnt_even % 2 != n % 2) {
            ans -= 2;
        }
    }
    cout << ans << endl;
}   

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}