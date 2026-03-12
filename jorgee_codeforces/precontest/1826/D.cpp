#include <iostream>
#include <vector>

using namespace std; 

void solve() {
    int n;
    cin >> n;

    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    vector<int> pre(n), suf(n);
    for (int i = 0; i < n; i++) {
        pre[i] = A[i] + i;
        suf[i] = A[i] - i;
    }
    
    for (int i = 1; i < n; i++) {
        pre[i] = max(pre[i], pre[i-1]);
    }

    for (int i = n-2; i >= 0; i--) {
        suf[i] = max(suf[i], suf[i+1]);
    }

    int ans = 0;
    for (int m = 1; m < n-1; m++) {
        ans = max(ans, A[m] + pre[m-1] + suf[m+1]);
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