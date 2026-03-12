#include <iostream>
#include <vector>

using namespace std; 

void solve() {
    int n, k;
    cin >> n >> k;

    if (k & 1) {
        for (int i = 0; i < k; i++) {
            cout << n << " \n"[i+1==k];
        }
    } else {
        cout << 0 << " ";
        for (int i = 0; i < k-1; i++) {
            cout << n << " \n"[i+1==k-1];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
    return 0;   
}