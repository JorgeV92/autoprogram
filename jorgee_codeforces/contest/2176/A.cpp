#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int mx = a[0];
    int total = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] < mx) {
            total++;
        } else {
            if (a[i] >= mx) {
                mx = a[i];
            }
        }
    }
    cout << total << endl;
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