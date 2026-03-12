#include <iostream>
#include <vector>
#include <set>

using namespace std; 

void solve() {
    int l, a, b;
    cin >> l >> a >> b;
    set<int> st;
    int ans = 0;
    int i = 1;
    while (true) {
        int p = (a + i*b) % l;
        if (st.find(p) == st.end()) {
            st.insert(p);
            i++;
        } else {
            break;
        }
    }

    cout << *st.rbegin() << endl;
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
