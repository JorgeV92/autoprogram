#include <iostream>
#include <vector>

using namespace std;

// 312. Burst Ballons
//
// find the maximum coins you can collect by bursting ballonons. 
//


//
//  [2, 3, 7, 5, 10]
//  [2, 3, 5, 10]
//

// maybe dp[L][R]
//  
// instead of thinking about which balloon to pop first 
// I should consider which balloon to pop last. 
// 
// We consider the following a[i] * a[L-1] * a[R+1] + dp[L][i-1] + dp[i+1][R]



class Solution {
public:
    int maxCoins(vector<int>& A) {
        const int n = A.size();
        if (A.empty()) return 0;
        vector<vector<int>> dp(n, vector<int>(n));
        for (int L = n-1; L >=0; L--) {
            for (int R = L; R < n; R ++) {
                for (int i = L; i <= R; i++) {
                    int left_A = (L ? A[L-1] : 1);
                    int right_A = (R == n-1 ? 1 : A[R+1]); 
                    int l_part = (L <= i-1 ? dp[L][i-1] : 0);
                    int r_part = (i+1 <= R ? dp[i+1][R] : 0);
                    dp[L][R] = max(dp[L][R], A[i] * left_A * right_A + l_part + r_part);  
                }
            }
        }
        return dp[0][n-1];  
    }

};


int main() {
    return 0;
}
