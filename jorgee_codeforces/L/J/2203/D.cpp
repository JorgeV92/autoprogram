#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    vector<int> cnt(n+m+1);
    for (int x : a) {
        cnt[x]++;
    }

    for (int i = m+n; i >= 1; i--) {
        for (int j = i*2; j <= n + m; j += i) {
            cnt[j] += cnt[i];
        }
    }
    int ca =0 , cb = 0, cz = 0;
    for (auto x : b) {
        if (cnt[x] == n) {
            ca++;
        } else if (cnt[x] == 0) {
            cb++;
        } else {
            cz++;
        }
    }

    if (cz % 2 + ca > cb) {
        cout << "Alice\n";
    } else {
        cout << "Bob\n";
    }
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
