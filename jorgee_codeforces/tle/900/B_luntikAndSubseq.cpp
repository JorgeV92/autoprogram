#include <iostream>
#include <vector>

using namespace std; 

using ll = long long;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        ll cnt0 = 0, cnt1 = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x == 0) {
                cnt0++;
            } 
            if (x == 1) {
                cnt1++;
            }
        }
        
        cout << (1ll << cnt0) * cnt1 << '\n';
    }
    return 0;   
}