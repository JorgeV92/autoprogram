#include <iostream>
#include <vector>
#include <set>

using namespace std; 

#define ll long long

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    int mx = 0;
    for (int i = 0; i < n; i++) {
        int x; 
        cin >> arr[i];
    }
    ll b = 0;
    for (int i = 0; i < n-1; i++) {
        b += abs(arr[i] - arr[i+1]);
    }
    ll ans = b;
    ans = min(ans, b - abs(arr[0] -arr[1]));
    ans = min(ans, b - abs(arr[n-2] -arr[n-1]));
    for (int i = 1; i < n-1; i++) {
        ll remove = abs(arr[i] - arr[i-1]) + abs(arr[i] - arr[i+1]);
        ll add = abs(arr[i-1] - arr[i+1]);
        ans = min(ans, b - remove + add);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}