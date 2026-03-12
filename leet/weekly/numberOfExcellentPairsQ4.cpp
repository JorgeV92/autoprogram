#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        set<int> st(nums.begin(), nums.end());
        vector<int> a;
        for (auto x : st) {
            int cnt = __builtin_popcount(x);
            a.push_back(cnt);
        }
        sort(a.begin(), a.end());
        long long ans = 0;
        int n = a.size();
        int l =0, r = n-1;
        while (l < n && r >= 0) {
            if (a[l] + a[r] < k) {
                l++;
            } else {
                ans += (n-l);
                r--;
            }
        }
        return ans;
    }
};

class ASolution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        set<int> st(nums.begin(), nums.end());
        vector<int> a;
        a.reserve(st.size());
        for (int x : st) a.push_back(__builtin_popcount((unsigned)x));

        sort(a.begin(), a.end());
        int n = (int)a.size();

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int need = k - a[i];
            auto it = lower_bound(a.begin(), a.end(), need);
            ans += (a.end() - it);   // count of j such that a[j] >= need
        }
        return ans;
    }
};