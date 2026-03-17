#include <iostream>
#include <vector>
#include <queue>

using namespace std;

using ll = long long;

class Solution {
public:
    ll kSum(vector<int>& arr, int k) {
        int n = arr.size();
        ll mx = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] > 0) {
                mx += arr[i];
            } else {
                arr[i] *= -1;
            }
        }
        sort(arr.begin(), arr.end());
        using pli = pair<ll, int>;
        priority_queue<pli, vector<pli>, greater<pli>> pq;
        pq.push({0,0});
        while (--k) {
            auto p = pq.top();
            pq.pop();
            ll sum = p.first;
            int i = p.second;
            if ( i < n) {
                pq.push({sum + arr[i], i+1});
                if (i) {
                    pq.push({sum + arr[i] - arr[i-1], i+1});
                }
            }
        }
        return mx - pq.top().first;
    }
};

int main() {   
    ios::sync_with_stdio(0); cin.tie(0);
    Solution sol;
    vector<int> a{2, 4, -2};
    cout << sol.kSum(a, 5) << "\n";
    return 0;   
}