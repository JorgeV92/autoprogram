#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin>> n;
    vector<int> cnt(2*n);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        a--;
        cnt[a]++;
    }
    bool valid = true;
    for (int i = 0; i < 2*n; i++) {
        if (cnt[i] == 1) {
            cout << "NO\n";
            return;
        }
        if (cnt[i] > 2) {
            cnt[i+1] += cnt[i] - 2;
        }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}