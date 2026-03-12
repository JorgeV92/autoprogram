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
        int zeros = 0;
        int z = -1;
        int r = -1;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            if (arr[i] == 0) {
                if (z == -1) 
                    z = i;
                r = i;
            }
            
        }
        if (z == -1) {
            cout << "Alice\n";
        } else {
            if (z == 0 && r == n-1) {
                cout << "Bob\n";
            } else {
                cout << "Alice\n";
            }
        }
        
    }
    return 0;
}