#include <iostream>
#include <vector>

using namespace std; 

void solve() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0 ;i <n; i++) {
        cin >> arr[i];
    } 

    int e = -1;
    int cnt = 0;
    for (int x : arr) {
        if (e == x) {
            cnt++;
        } else if (cnt == 0) {
            e = x;
            cnt++;
        } else {
            cnt--;
        }
    }

    cnt = 0;
    for (int x : arr) {
        if (e == x) 
            cnt++;
    }

    if (cnt > n/2) 
        cout << e << endl;
    else 
        cout << -1 << endl;
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