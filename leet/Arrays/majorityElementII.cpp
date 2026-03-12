#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n; 
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int e1 = -1, e2 = -1;
    int cnt1 = 0, cnt2 = 0;

    for (int x : arr ){
        if (e1 == x) {
            cnt1++;
        } else if (e2 == x) {
            cnt2++;
        } else if (cnt1 == 0) {
            cnt1++;
            e1 = x;
        } else if (cnt2 ==0 ){
            cnt2++;
            e1 = x;
        } else {
            cnt1--;
            cnt2--;
        }
    }

    cnt1 = 0; cnt2 = 0;
    for (int x : arr) {
        if (e1 == x) cnt1++;
        if (e2 == x) cnt2++;
    }

    if (cnt1 > n/3)
        cout << e1 << endl;
    if (cnt2 > n/3 && e1 != e2) 
        cout << e2 << endl;
    
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
