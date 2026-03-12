#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n;
    cin >> n;

    if (n==0) return 0;

    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    auto print_dp = [](vector<vector<int>>& dp) {
        int sz = dp.size();
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < sz; j++) {
                cout << " | " << dp[i][j] << " | "; 
            }
            cout << endl;
        }
    };
    
    // dp[L][R] = maximum coins we can get by bursting all balloons in A[L..R],
    // assuming that every balloon outside this range is still intact.
    // In particular, when we burst the *last* balloon in A[L..R],
    // its neighbors will be A[L-1] (or 1 if L == 0) and A[R+1] (or 1 if R == n-1).
    vector<vector<int>> dp(n, vector<int>(n)); 
    
    for (int L = n-1; L >= 0; L--) {
        for (int R = 0; R < n; R++) {
            for (int i = L; i <= R; i++) {
                int a_left = (L ? A[L-1] : 1);
                int a_right = (R==n-1 ? 1 : A[R+1]);
                int left_interval = (L<=i-1? dp[L][i-1] : 0);
                int right_interval = (i+1<=R ?dp[i+1][R] : 0);
                dp[L][R] = max(dp[L][R], A[i] * a_left * a_right + left_interval + right_interval);
            }
        }
    }
   // print_dp(dp);

    cout<< dp[0][n-1] << endl;
    

    return 0;
}
