#include <iostream>
#include <vector>

using namespace std; 

vector<vector<int>> permute(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> allp;
    vector<int> p;
    vector<bool> vis(n+1);

    auto dfs = [&](auto&& dfs) {
        if (p.size() == n) {
            allp.push_back(p);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                p.push_back(nums[i]);
                vis[i] = true;
                dfs(dfs);
                p.pop_back();
                vis[i] = false;
            }
        }
    };

    dfs(dfs);
    return allp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}