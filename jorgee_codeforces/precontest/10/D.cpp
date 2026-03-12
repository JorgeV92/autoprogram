#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> A(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    int m; 
    cin >> m;
    vector<int> B(m+1);
    for (int i = 1; i <= m; i++) {
        cin >> B[i];
    }

    vector<vector<int>> dp(n+1, vector<int>(m+1));
    vector<vector<int>> p(n+1, vector<int>(m+1));

    for (int i = 1; i <= n; i++) {
        int pr = 0;
        for (int j = 1; j <= m; j++) {
            if (A[i] == B[j]) {
                dp[i][j] = dp[i-1][pr] + 1;
                p[i][j] = pr;
            } else {
                dp[i][j] = dp[i-1][j];
                p[i][j] = j;
                if (A[i] > B[j] && dp[i-1][j] > dp[i-1][pr]) {
                    pr = j;
                }
            }
        }
    }

    int f = 0;
    for (int j = 1; j <= m; j++) {
        if (dp[n][f] < dp[n][j]) 
            f = j;
    }

    vector<int> ans;
    for (int i = n; i > 0; i--) {
        if (A[i] == B[f] && f != p[i][f]) {
            ans.push_back(A[i]);
        }
        f = p[i][f];
    }
    cout << ans.size() << endl;
    for (int i = ans.size() - 1; i >= 0; i--) 
        cout << ans[i] << " \n"[!i];
    
    return 0;
}