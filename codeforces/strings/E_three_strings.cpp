#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        string a, b, c;
        cin >> a >> b >> c;
        int na = int(a.size());
        int nb = int(b.size());
        vector<vector<int>> f(na+1, vector<int>(nb+1, na + nb + 1));
        f[0][0] = 0;
        for (int i = 0; i <= na; i++) {
            for (int j = 0; j <= nb; j++) {
                int k = i + j;
                if (i < na)
                    f[i+1][j] = min(f[i+1][j], f[i][j] + int(a[i] != c[k]));
                if (j < nb)
                    f[i][j+1] = min(f[i][j+1], f[i][j] + int(b[j] != c[k]));
            }
        }
        cout << f[na][nb] << "\n";
    }
    return 0;
}
