#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        int mn = 1e9;
        vector<int> allmin;
        for (int i = 0; i < n; i++) {
            int m;
            cin >> m;
            vector<int> v(m);
            for (auto& el : v) cin >> el;
            int minel = *min_element(v.begin(), v.end());
            mn = min(mn, minel);
            v.erase(find(v.begin(), v.end(), minel));
            allmin.push_back(*min_element(v.begin(), v.end()));
       }
       cout << mn + accumulate(allmin.begin(), allmin.end(), 0LL) - *min_element(allmin.begin(), allmin.end());
       cout << '\n';
    }
    return 0;
}