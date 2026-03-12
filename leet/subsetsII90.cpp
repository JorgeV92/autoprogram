#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> alls;
    vector<int> subs;
    sort(nums.begin(), nums.end());

    auto dfs = [&](auto&& dfs, int ii) {
        if (ii == n) {
            alls.push_back(subs);
            return;
        }
        subs.push_back(nums[ii]);
        dfs(dfs, ii+1);
        subs.pop_back(); 

        while (ii+1 < n && nums[ii] == nums[ii+1]) ii++;
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