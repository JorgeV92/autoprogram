#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> l(n+1);
        l[0] = 0;
        for (int i = 1; i <= n; i++) {
            cin >> l[i];
        }
        l.push_back(x);
        int mn = 0;
        for (int i = 1; i < l.size(); i++) {
            if (l[i] == x) {
                mn = max(mn, abs(l[i] - l[i-1]) * 2);
            } else {
                mn = max(mn, abs(l[i] -l[i-1]));
            }
        }
        cout << mn << endl;
    }

    return 0;
}