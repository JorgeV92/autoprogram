#include <iostream>
#include <vector>

using namespace std;

int dp[205][205];
int suffix[101];
int n;

int solve(int i, int M, vector<int>& piles) {
    if (i >= n) return 0;
    if (n-i <= 2*M) {
        return suffix[i];
    }
    if (dp[i][M] != -1) return dp[i][M];

    int mx = 0;
    for (int X = 1; X <= 2*M; X++) {
        int opp = solve(i+X, max(X, M), piles);
        int score = suffix[i] - opp;
        mx = max(mx, score);
    }
    return dp[i][M] = mx;
}

int stoneGameII(vector<int>& piles) {
    int n = piles.size();
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= 2 * n; j++) {
            dp[i][j] = -1;
        }
    }

    suffix[n] = 0;
    for (int i = n-1; i >= 0; i--) {
        suffix[i] = suffix[i+1] + piles[i];
    }

    return solve(0, 1, piles);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}