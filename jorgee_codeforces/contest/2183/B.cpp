#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            arr[i] = min(arr[i], n+1);
        }
        vector<int> freq(n+2,0);
        for (int i = 0; i < n; i++) {
            freq[arr[i]]++;
        }
        ll mex = 0;
        while (freq[mex]) mex++;
        cout << min(mex, (ll)k-1) << '\n';
            
    }
    return 0;
}