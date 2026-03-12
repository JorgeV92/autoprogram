#include <iostream>
#include <vector>
#include <cmath>

using namespace std; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    if (arr[0] ==0) {
        cout << 0 << endl;
    } else {
        int mn = abs(arr[0]);
        for (int i = 1; i < n; i++) {
            if (arr[i] == 0) {
                cout << 0 << endl;
                return 0;
            } else if (abs(arr[i]) <= mn) {
                mn = abs(arr[i]);
            } 
        }
        cout << mn << endl;
    }   
    return 0;
}