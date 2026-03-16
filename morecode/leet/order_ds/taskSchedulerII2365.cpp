#include <iostream>
#include <vector>
#include <map>

using namespace std;

using ll = long long;

class Solution {
public:
    ll taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<ll, ll> day;
        ll ans = 0;
        for (auto& t : tasks) {
            ans++;
            ans = max(ans, day[t]);
            day[t] = ans + space + 1;
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    Solution sol;
    vector<int> tas{1,2,1,2,3,1};
    ll ans = sol.taskSchedulerII(tas,3);
    cout << ans << '\n';
    return 0;
}