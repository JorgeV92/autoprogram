#include <iostream>
#include <vector>

using namespace std; 

 vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    int n = candidates.size();
    vector<vector<int>> alls;
    vector<int> sub;
    
    auto dfs = [&](auto&& dfs, int ii, int sum) {
        if (sum == target) {
            alls.push_back(sub);
            return;
        }
        if (ii == n || sum > target) return;
        sub.push_back(candidates[ii]);
        dfs(dfs, ii, sum + candidates[ii]);
        sub.pop_back();
        dfs(dfs, ii+1, sum);
    };
    dfs(dfs, 0, 0);
    return alls;
 }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}