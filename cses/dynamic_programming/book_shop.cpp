/**
 * Problem: Subset Sum / Coin Sums
 * Algorithm: Dynamic Programming (0/1 Knapsack style)
 * Time Complexity: O(N * Total Sum)
 */
#include <iostream>
#include <vector>

using namespace std;

const int MAX_TARGET = 1e5 + 4;
const int MAXN = 1005;
const int ninf = -(1e9+5);

int dp[MAXN][MAX_TARGET];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    vector<int> books(n), pages(n);
    for (int i = 0; i < n; i++) cin >> books[i];
    for (int i = 0; i < n; i++) cin >> pages[i];

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= x; j++) {
            dp[i][j] = dp[i-1][j];
            if (j - books[i-1] >= 0) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-books[i-1]] + pages[i-1]);
            } 
        }
    }

    cout << dp[n][x] << endl;

    return 0;
}