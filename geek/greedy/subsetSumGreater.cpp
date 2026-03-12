#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int minElements(vector<int>& arr) {
    int n = arr.size();
    int sum = accumulate(arr.begin(), arr.end(), 0);
    sort(arr.begin(), arr.end(), greater<int>());
    int res = 0;
    int currSum = 0;
    for (int i = 0; i < n; i++) {
        currSum += arr[i];
        res++;
        if (currSum > sum - currSum) {
            return res;
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr = { 3, 1, 7, 1 };
    cout << minElements(arr) << endl;
    
    return 0;
}