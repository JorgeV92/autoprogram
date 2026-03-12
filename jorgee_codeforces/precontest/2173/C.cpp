#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std; 


void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    set<int> A;
    map<int,int> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        A.insert(a[i]);
        mp[a[i]] = 1;
    }
    vector<int> ans;
    while (A.size()) {
        int mn = *A.begin();
        ans.push_back(mn);
        A.erase(A.begin());
        for (int mul = mn; mul <= k; mul += mn) {
            if (!mp[mul]) {
                cout << -1 << endl;
                return;
            }
            auto it = A.find(mul);
            if (it != A.end()) A.erase(it);
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " \n"[i+1 == ans.size()];
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