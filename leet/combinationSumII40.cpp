#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> combinationSum2(vector<int>& c, int t) {
    int n = c.size();
    sort(c.begin(), c.end());
    vector<vector<int>> alls;
    vector<int> sb;

    auto dfs = [&](auto&& dfs, int ii, int sum) {
        if (sum == t) {
            alls.push_back(sb);
            return;
        }
        if (ii == n || sum > t) return;
        sb.push_back(c[ii]);
        dfs(dfs, ii+1, sum +c[ii]);
        sb.pop_back();
        while (ii+1 < n && c[ii] == c[ii+1]) ii++;
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