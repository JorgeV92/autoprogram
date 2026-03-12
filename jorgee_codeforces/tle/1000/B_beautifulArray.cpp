#include <iostream>
#include <vector>

using namespace std;

void solve() {
    long long n, k, b, s;
    cin >> n >> k >> b >> s;
    vector<long long> a(n);
    a[0] = k * b;
    s -= k * b;
    if (s < 0) {
        cout << "-1\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        long long now = min(k-1, s);
        a[i] += now;
        s -= now;
    }
    if (s >0) {
        cout << "-1\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cout.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
