#include <iostream>
#include <vector>
#include <deque>

using namespace std;

using ll = long long;

class Solution {
public:
    int maximumRobots(vector<int> chargetimes, vector<int>& runcost, ll budget) {
        int n = chargetimes.size();
        deque<int> q;
        ll s= 0;
        int ans = 0;
        for (int l = 0, r = 0; r < n; r++) {
            s += runcost[r];
            while (q.size() && chargetimes[q.back()] <= chargetimes[r]) {
                q.pop_back();
            }
            q.push_back(r);
            while (q.size() && (r-l+1) * s + chargetimes[q.front()] > budget) {
                if (q.front() == l) {
                    q.pop_front();
                }
                s -= runcost[l++];
            }
            ans = max(ans, (r-l+1));
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    Solution sol;
    vector<int> a{3,6,1,3,4};
    vector<int> cost{2,1,3,4,5};
    cout << sol.maximumRobots(a, cost, 25) << '\n';
    return 0;
}