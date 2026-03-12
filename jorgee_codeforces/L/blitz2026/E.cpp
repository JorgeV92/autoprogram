#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<string> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int ans = 0;
        vector<vector<bool>> was(n, vector<bool>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (was[i][j]) continue;
                vector<int> cnt(2);
                int xi = i;
                int xj = j;
                for (int rot = 0; rot < 4; rot++) {
                    if (!was[xi][xj]) {
                        was[xi][xj] = true;
                        cnt[int(a[xi][xj] - '0')] += 1;
                    }
                    int ni = n - 1 - xj;
                    int nj = xi;
                    xi = ni;
                    xj = nj;
                }
                ans += min(cnt[0], cnt[1]);
            }
        }
        cout << ans << '\n';
    }
    return 0;   
}