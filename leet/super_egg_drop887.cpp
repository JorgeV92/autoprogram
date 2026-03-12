#include <iostream>
#include <vector>


using namespace std;

const int INF = 1e9 + 7;

int superEggDrop(int k, int n) {
    // one none optimal solution is the following 
    // we declare a start in a dp table as such 
    //
    //      dp[x][e] - is the number of moves we need to determine the value of f
    //                 using floor x and egg e. 
    // where each state we are at floor x and if it breaks we need to search floors x-1 with e-1 eggs.
    // and if it didnt break then we need to check n - x floors above with e eggs.
    // The following get TLE with time complexity O(N^2 * K) 
    vector<vector<int>> dp(n+1, vector<int>(k+1, INF)); 

    // base cases::
    for (int i = 1; i <= k; i++) {
        dp[0][i]  = 0;
    } 
    for (int i = 1; i <= n; i++) {
        dp[i][0] = i;
    }

    for (int i = 1; i <= n; i++) {
        for (int e = 2; e <= k; e++) {
            for (int f = 1; f <= i; f++) {
                int tmp = max(dp[f-1][e-1], dp[i-f][e]) + 1;
                dp[i][e] = min(dp[i][e], tmp);
            }
        }
    }

    return dp[n][k];
}
 
    
int main() {
    
    
    return 0;
}
