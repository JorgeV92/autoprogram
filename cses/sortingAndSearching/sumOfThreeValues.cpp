#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;
    vector<pair<int,int>> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++) {
        if (i > 0 && arr[i].first == arr[i-1].first) continue;
        int l = i+1, r = n-1;
        while (l < r) {
            int sum = arr[i].first + arr[l].first + arr[r].first;
            if (sum == x) {
                cout << arr[i].second+1 << " " << arr[l].second +1<< " " << arr[r].second+1 << endl;
                return 0;
            } else if (sum < x) {
                l++;
            } else {
                r--;
            }
        }
    }
    cout << "IMPOSSIBLE\n";

    return 0;
}