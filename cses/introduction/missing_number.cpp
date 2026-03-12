#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n-1; i++) {
        cin >> arr[i];
    }    

    int x = 0;
    for (int i = 0; i < n-1; i++) {
        x ^= arr[i];
        x ^= (i+1);
    }
    x ^= n;

    cout << x << endl;

    return 0;
}
