#include <iostream>
#include <vector>

using namespace std; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n; 
        cin >> n;
        vector<int> arr(n);
        int total = 0;
        for (int i = 0 ; i < n; i++) {
            cin >> arr[i];
            total += (arr[i] == 2?1:0);
        }
        if (total % 2 == 0) {
            int k = 0;
            for (int i = 0; i < n; i++) {
                k += (arr[i]==2?1:0);
                if (k == total/2) {
                    cout << i+1 << endl;
                    break;
                }
            }
        } else {
            cout << -1 << endl;
        }
        
    }
    return 0;
}
