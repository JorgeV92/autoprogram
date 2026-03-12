#include <iostream>
#include <vector>
#include <functional>

using namespace std;

/*
    You are given n ballons indexed from 0 to n-1. Each balloon is painted with a number 
    on it represented by an array nums. You are asked to burst all balloons.

    If you burst the ith balloon, you will get nums[i-1] * nums[i] * nums[i+1] coins.
    If i - 1 or i + 1 goes out of bounds of the array, then treat as if there is a balloon with     
    a 1 painted on it.

    RETURN THE MAXIMUM COINS YOU CAN COLLECT BY BUSRTING THE BALLOONS WISELY.

    Input: [3, 1, 5, 8]
    Output: 167

    [3, 1, 5, 8] -> [3, 5, 8] -> [3 ,8] -> [8] -> []
        3*1*5     +   3*5*8   +   1*3*8  +  1*8*1 = 167


    For Dynamic programming we can think about complexity in two parts 
    one for number of states and time spent on each state.
        
*/

void max_coins_dp_top_down(vector<int>& A) {
    // O(N^3) time - there are N^2 states and we need N time to burst the last balloon
    // O(N^2) space 
    const int n = A.size();
    A.insert(A.begin(), 1);
    A.insert(A.end(), 1);
    
    vector<vector<int>> memo(n, vector<int>(A.size(), 0));
    
    functional<int(int,int)> max_reward = [&](int left, int right) -> int {
        if (right - left < 0) {
            return 0;
        }

        if (memo[left][right] > 0) {
            return memo[left][right];
        }

        int res = 0;
        for (int i = left; i <= right; i++) {
            int gain = A[left-1] * A[i] * A[right+1];
            int remaining = max_reward(left, i-1) + max_reward(i+1, right);
            res = max(res, gain + remaining);
        }

        return memo[left][right] = res;
    };    

    cout << max_reward(1, A.size()-2);
} 

int max_coins_do_bottom_up = [&](const vector<int>& A) {
    A.insert(A.begin(), 1);
    A.insert(A.end(), 1);
    
    // dp[left][right] - is the maximum reward by popping all ballons in interval [left, right] inclusive.
    vector<vector<int>> dp(A.size(), vector<int>(A.size(), 0));

    for (int left = A.size()-2; left >= 1; left--) {
        for (int right = 1; right <= A.size()-2; right++) {
            // A[i] is the last balloon to pop
            for (int i = left; i <= right; i++) {
                int reward = A[left-1] * A[i] * A[right+1];
                int remaining = dp[left][i-1] + dp[i+1][right];
                dp[left][right] = max(dp[left][right], reward + remaining); 
            }
        }
    }

    return dp[1][A.size()-2];
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(false);
        
    int n;
    cin >> n;

    vector<int> coins(n);
    for (int& a : coins) {cin >> coins[i]; }



    return 0;
}
