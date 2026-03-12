#include <iostream>
#include <vector>

using namespace std;


// 1155. Number of Dice Rolls with Target Sum 
// 

const int MOD = 1e9 + 7;

int numRollsToTarget(int d, int f, int target) {
    // dp[s] -> the number of ways to get sum 's' so far

    vector<int> ways(target+1); 
    ways[0] = 1;
    for (int rep = 1; rep <= d; rep++) {
        vector<int> new_ways(target+1);
        for (int have = 0; have <= target; have++) {
            for (int face = 1; face <= f; face++) {
                if (have + face <= target) {
                    int& tmp = new_ways[have+face];
                    tmp += ways[have];
                    if (tmp >= MOD) {
                        tmp -= MOD;
                    }
                }
            }
        }
        ways = new_ways;
    }

    return ways[target];
}


int main() {

    return 0;
}
