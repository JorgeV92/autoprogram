#include <iostream>
#include <vector>
#include <string>
#include <cstring>

const int MOD = 1e9 + 7;

void addi(int& a, int b) {
    a += b;
    if (a >= MOD) {
        a -= MOD;
    }
}

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    auto printGrid = [&]() {
        for (int i = 0; i < n; i++) {
            cout << grid[i] << endl;
        }
    };

    if (grid[0][0] == '*') {
        cout << 0 << endl;
        return 0;
    }        

    //dp[x][y] - is the number of ways to reach cell (x, y) from (x-1, y) and (x, y-1) 
    int dp[1000][1000];
    memset(dp, 0, sizeof(dp));

    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '*') 
                continue;
            if (i > 0) {
                addi(dp[i][j], dp[i-1][j]);
            }
            if (j > 0) {
                addi(dp[i][j], dp[i][j-1]);
            }
        }
    }
    cout << dp[n-1][n-1] << endl;

    return 0;
}