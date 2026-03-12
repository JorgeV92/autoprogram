#include <iostream>
#include <vector>

using namespace std;

 int subsetXORSum(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> allS;
    vector<int> sub;

    auto back = [&](auto&& back, int ii) {
        if (ii == n) {
            allS.push_back(sub);
            return;
        }

        sub.push_back(nums[ii]);
        back(back, ii+1);
        sub.pop_back();
        back(back, ii+1);
    };

    back(back, 0);

    int total = 0;
    for (auto& a : allS) {
        int t = 0;
        for (int x : a) {
            t ^= x;
        }
        total += t;
    }
    
    return total;
 }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}