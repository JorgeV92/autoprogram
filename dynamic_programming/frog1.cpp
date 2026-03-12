#include <iostream>
#include <vector>

using namespace std;


int main() {
        
    int n;
    cin >> n;

    vector<int> stones(n);
    for (int& a : stones) {
        cin >> a;
    }

    // define dp[i] to be the minimum number of stones to jump to i from i - 1 jump or i - 2 jump
    vector<int> dp(n, INT_MAX);

    dp[0] = 0;
 
    for (int i = 1; i < n; i++) {i
        // jump one stone
        if (i - 1 >= 0) {
            dp[i] = min(dp[i], dp[i-1] + abs(stones[i] - stones[i-1]));
        }

        // jump two stones
        if (i - 2 >= 0) {
            dp[i] = min(dp[i], dp[i-2] + abs(stones[i] - stones[i-2]));
        }
    }

    cout << dp[n-1] << endl;

    return 0;
}








