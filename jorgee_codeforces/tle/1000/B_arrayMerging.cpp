#include <iostream>
#include <vector>

using namespace std;

void solve() { 
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) { 
        cin >> a[i];
        a[i]--;
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        b[i]--;
    }

    vector<int> fa(2*n), fb(2*n);
    int len = 0;
    for (int i =0 ; i < n; i++) {
        if (i > 0 && a[i] != a[i-1]) {
            len = 0;
        }
        len++;
        fa[a[i]] = max(fa[a[i]], len);
    }
    len = 0;
    for (int i = 0 ; i < n; i++) {
        if (i > 0 && b[i] != b[i-1]) {
            len = 0;
        }
        len++;
        fb[b[i]] = max(fb[b[i]], len);
    }
    int ans = 0;
    for (int i = 0; i < 2 * n; i++) {
        ans = max(ans, fa[i] + fb[i]);
    }
    cout << ans << "\n";
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

