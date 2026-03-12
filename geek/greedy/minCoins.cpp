#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int minCoins(vector<int>& arr, int amount) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int res = 0;
    for (int i = n-1; i >= 0; i--) {
        if (amount >= arr[i] ) {
            int cnt = (amount / arr[i]);
            res += cnt;
            amount -= (cnt * arr[i]);
        }
        if (amount==0) break;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> coins{5, 2, 10, 1};
    int amount = 39;
    cout << minCoins(coins, amount) << endl; 

    return 0;
}