#include <iostream>
#include <vector>

using namespace std; 

 vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> allc;
    vector<int> sub;

    auto dfs = [&](auto&& dfs, int ii) {
        if (sub.size() == k) {
            allc.push_back(sub);
            return;
        }
        if (ii == n) return;
        sub.push_back(ii+1);
        dfs(dfs, ii+1);
        sub.pop_back();
        dfs(dfs, ii+1);
    };
    dfs(dfs, 0);
    return allc;
 }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}