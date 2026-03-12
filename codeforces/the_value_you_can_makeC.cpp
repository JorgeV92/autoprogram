#include <iostream>
#include <vector>

using namespace std;

bool dp[2][505][505];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; 
    cin >> n >> k;

    dp[0][0][0] = 1;
    for (int i = 1; i <= n; i++) {
        int now = i % 2;
        int last = 1 - now;
        int x;
        cin >> x;
        for (int j = 0; j <= k; j++) {
            for (int y = 0; y <= j ; y++) {
                dp[now][j][y] |= dp[last][j][y];
                if (j >= x) {
                    dp[now][j][y] |= dp[last][j-x][y]; 
                } 
                if (y >= x) {
                    dp[now][j][y] |= dp[last][j-x][y-x];
                }
            }
        } 
    }

    vector<int> ans;
    for (int i = 0; i <= k; i++) {
        if (dp[n%2][k][i]) {
            ans.push_back(i);
        }
    }
    cout << ans.size() << endl;
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}