#include <iostream>
#include <vector>
#include <numeric>
#include <cstdint>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) 
            cin >> a[i];
        vector<int> p(n);
        iota(p.begin(), p.end(), 0);
        sort(p.begin(), p.end(), [&](int i, int j) {return a[i] < a[j];});
        vector<int> ans(n); 
        int64_t s = 0;
        for (int i = 0, j = 0; i < n; i++) {
            if (j == i) {
                j++;
                s += a[p[i]];
            }
            while (j < n && s >= a[p[j]]) {
                s += a[p[j]];
                j++;
            }
            ans[p[i]] = j -1;
        }
        for (int i = 0; i < n; i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
    return 0;   
}