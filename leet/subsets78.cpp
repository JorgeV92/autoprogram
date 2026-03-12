#include <iostream>
#include <vector>

using namespace std; 

vector<vector<int>> subsets(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> alls;
    vector<int> sub;

    auto dfs = [&](auto&& dfs, int ii) {
        if (ii == n) {
            alls.push_back(sub);
            return;
        }
        sub.push_back(nums[ii]);
        dfs(dfs, ii+1);
        sub.pop_back();
        dfs(dfs, ii+1);
    };

    dfs(dfs, 0);
    return alls;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}