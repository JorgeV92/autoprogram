#include <iostream>
#include <vector>

using namespace std;

/*
    Given an array arr[] of non-negative integers and an integer target. 
    The task is to print all subsets of the array whose sum is equal to 
    the given target.
    Note: If no subset has a sum equal to target, print -1.
*/

// Brute force recursion 
// O(2^n) time and O(n) space

vector<vector<int>> res;

void print_array() {
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << " | " << res[i][j] << " | " << " \n"[j+1 == res[i].size()];
        }
    }
}

void findSubsetsRecusrion(vector<int>& arr, int k) {
    int n = arr.size();
    res.assign(n, {});
    vector<int> subset;

    auto dfs = [&](auto&& dfs, int idx, int sum) {
        if (idx >= n) {
            if (sum == 0) {
                res.push_back(subset);
                return;
            }
            return; // no valid subset
        }
        subset.push_back(arr[idx]);
        dfs(dfs, idx+1, sum-arr[idx]);
        subset.pop_back();
        dfs(dfs, idx+1, sum);
    };

    dfs(dfs, 0, k);
}

// DP 
// O(2^n) time and O(n * k) space



void findSubsetsDP(vector<int>& arr, int k) {
    int n = arr.size();
     vector<vector<bool>> dp(n, vector<bool>(k+1));
     dp[0][0] = true;
     if (arr[0] <= k) dp[0][arr[0]] = true;

     for (int i = 1; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            dp[i][j] = dp[i-1][j] ||
                        (arr[i] <= j && dp[i-1][j-arr[i]]);
        }
     }

     if (!dp[n-1][k]) {
        cout << "Not Possible\n";
     }
     vector<int> subset;

     auto dfs = [&](auto&&dfs, int idx, int sum) {
        if (idx == 0) {
            if (sum == 0) res.push_back(subset);
            if (arr[0] == sum) {
                subset.push_back(arr[0]);
                res.push_back(subset);
                subset.pop_back();
            }
            return;
        }

        if (dp[idx-1][sum]) {
            dfs(dfs, idx-1, sum);
        }

        if (sum >= arr[idx] && dp[idx-1][sum-arr[idx]]) {
            subset.push_back(arr[idx]);
            dfs(dfs, idx-1,sum-arr[idx]);
            subset.pop_back();
        }
     };

     dfs(dfs, n-1, k);
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr = {5, 2, 3, 10, 6, 8};
    int target = 10;
    
    findSubsetsDP(arr, target);
    print_array();

    return 0;
}