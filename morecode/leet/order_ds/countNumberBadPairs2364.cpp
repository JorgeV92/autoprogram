#include <iostream>
#include <vector>
#include <map>

using namespace std;

using ll = long long;

class Solution {
public:
    ll countBadPairs(vector<int>& arr) {
        unordered_map<ll, ll> cnt;
        ll res = 0;
        for (int i = 0; i < (int)arr.size(); i++) {
            int x = i - arr[i];
            res += i - cnt[x]++;
        }
        return res;
    }  
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    Solution sol;
    vector<int> a{4,1,3,3};
    cout << sol.countBadPairs(a) << '\n';
    return 0;
}