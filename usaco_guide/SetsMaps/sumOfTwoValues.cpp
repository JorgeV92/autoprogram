#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) 
        cin >> arr[i];

    map<int,int> mp; // (num, idx)

    for (int i = 0; i < n; i++) {
        int diff = x - arr[i];
        if (mp.count(diff)) {
            cout << mp[diff] + 1 << " " << i+1 << endl;
            return 0;
        }
        mp[arr[i]] = i;
    }
    cout << "IMPOSSIBLE\n";

    return 0;
}