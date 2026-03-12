#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

void add(int& a, int b) {
    a += b;
    if (a >= MOD) {
        a -= MOD;
    }
}

int main() {
    
    int d, f, t;
    cin >> d >> f >> t;

    // d[i][x] - is the number of ways to achieve sum x using roll i.
    vector<vector<int>> dp_2(d+1, vector<int>(t+1));
    dp_2[0][0] = 1;
    // dp[x] -  is the number of ways to roll a die equal to x.
    vector<int> dp(t+1);
    dp[0] = 1;
    for (int i = 1; i <= d; i++) {
        vector<int> new_dp(t+1);
        for (int x = 0; x <= t; x++) {
            for (int face = 1; face <= f; face++) {
                if (x - face > =0) { 
                    add(new_dp[x], dp[x-face]);
                   add(dp[i][x], dp[i-1][x-face]); 
                }
            }
        } 
        dp = new_dp;
    }
   //  cout << dp[d][target];
    cout << dp[t] <<  endl;

    return 0;
}
