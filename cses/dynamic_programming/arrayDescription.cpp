#include <iostream>
#include <vector>

using namespace std; 

const int mod = 1e9 + 7;

void addi(int& a, int b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> dp(n, vector<int>(m+1));
    int x0;
    cin >> x0;
    if (x0 == 0) {
        fill(dp[0].begin(), dp[0].end(), 1);
    } else {
        dp[0][x0] = 1;
    }
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        if (x == 0) {
            for (int j = 1; j <= m; j++) {
                for (int k : {j-1, j,j+1}) {
                    if (k >= 1 && k <= m) {
                        addi(dp[i][j], dp[i-1][k]);
                    }
                }
            }
        } else {
            for (int k : {x-1, x, x+1}) {
                if (k >= 1 && k <= m) {
                    addi(dp[i][x], dp[i-1][k]);
                }
            }
        }
    }

    int ans = 0;
    for (int j = 1; j <= m; j++) {
        addi(ans, dp[n-1][j]);
    }
    cout << ans << endl;
    return 0;
}