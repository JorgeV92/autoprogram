#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define ll long long;

void solve() {
    int n;
    cin >> n;
    set<int> se;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        se.insert(a);
    }
    /*
        or found solution is to do 
        *se.lower_bound(se.size())
    */
    if (se.size() == 1) {
        cout << *se.begin() << endl;
        return;
    }
    int sz = se.size();
    while(true) {
        se.insert(sz);
        if (se.size() == sz) {
            break;
        } 
        sz = se.size();
    } 
    cout << se.size() << endl;
    
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