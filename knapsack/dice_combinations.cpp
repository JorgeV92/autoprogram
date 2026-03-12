#include <iostream>
#include <vector>


using namespace std;

const int MOD = 1e9 + 7;

int main() {
    
    int n;
    cin >> n;

    // dp[x] is the number of ways we can achieve sum x
    vector<int> ways(n+1);
    ways[0] = 1; // only one way to achieve sum 0

    for (int curr_sum = 1; curr_sum <= n; curr_sum++) {
        for (int f = 1; f <= 6; f++) {
            if (curr_sum-f >= 0) {
                ways[curr_sum] += ways[curr_sum-f];
                if (ways[curr_sum] >= MOD) {
                    ways[curr_sum] -= MOD;
                }
            }
        }
    }

    cout << ways[n] << endl;

    return 0;
}
