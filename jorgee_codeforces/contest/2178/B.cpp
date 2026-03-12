#include <iostream>
#include <vector>
#include <string>

using namespace std; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string r;
        cin >> r;
        int n = r.size();
        int ans = 0;
        if (r[0] == 'u') { 
            r[0] = 's';
            ans++;
        }
        if (r[n-1] == 'u') {
            ans++;
            r[n-1] = 's';
        }
        for (int i = 1; i < n-1; i++) {
            if (r[i] == 'u' && r[i+1] == 'u') {
                r[i+1] = 's';
                ans++;
            }
        }
        cout << ans << endl;

    }
    return 0;
}