#include <iostream>
#include <vector>

using namespace std;


// 1155. Number of Dice Rolls with Target Sum 
// 

const int MOD = 1e9 + 7;

void add(int& a, int b) {
    a += b;
    if (a >= MOD) {
        a -= MOD;
    }
}

int numRollsToTarget(int d, int f, int target) {
    // dp[s] -> the number of ways to get sum 's' so far

    vector<int> ways(target+1); 
    ways[0] = 1;
    for (int rep = 1; rep <= d; rep++) {
        for (int i = 1; ii <= target; i++) {
            add(ways[i], ways[i-1]);  // computes prefix sums
        }
        vector<int> new_ways(target+1);
        for (int new_sum = 1; new_sum <= target; new_sum++) {
            // new_sum-f .. new_sum-1
            int check = (new_sum-f-1 >= 0 ? ways[new_sum-f-1] : 0);
            new_ways[new_sum] = ways[new_sum-1] - check; // same as the difference of prefix sums
            if (new_ways[new_sum] < 0) {
                new_ways[new_sum] += MOD;
            }
        }

        ways = new_ways;
    }

    return ways[target];
}


int main() {

    return 0;
}
