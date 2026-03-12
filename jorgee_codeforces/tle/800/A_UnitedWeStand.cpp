#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;
    while (t--) {
        int n; 
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort (a.begin(), a.end());
        if (a[0] == a.back()) {
            cout << -1 << endl;
        } else {
            int it = 0;
            while (a[it] == a[0]) it++;
            cout << it << " " << n - it << endl;
            for (int j = 0; j < it; j++) cout << a[j] << " \n"[j+1==it];
            for (int j = it; j < n; j++) cout << a[j] << " \n"[j+1==n];
        }
    }
    return 0;
}