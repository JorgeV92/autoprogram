#include <iostream>
#include <vector>

using namespace std; 

constexpr int N = 2e5 + 7;
constexpr int INF = 1e9;

int dp[N][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for (int i = 0; i <= n; i++) {
            dp[i][0] = INF;
            dp[i][1] = INF;
        }

        dp[0][1] = 0;
        for (int i = 0; i < n; i++) {
            for (int who = 0; who < 2; who++) {
                for (int f = 1; f <= min(n-i, 2); f++) {
                    int hard = a[i] + (f > 1 ? a[i+1]: 0);
                    dp[i+f][!who] = min(dp[i+f][!who], dp[i][who] + who*hard);
                }
            }
        }

        cout << min(dp[n][0], dp[n][1]) << endl;
    }

    return 0;
}