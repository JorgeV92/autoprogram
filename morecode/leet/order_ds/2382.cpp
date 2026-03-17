#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

using ll = long long;

class Solution {
public:
    vector<int> p;
    vector<ll> s;
    vector<ll> maximumSegementSum(vector<int>& arr, vector<int>& queries) {
        int n = arr.size();
        p.resize(n);
        s.resize(n,0);
        for (int i = 0; i< n; i++) p[i ]= i;
        vector<ll> res(n);
        ll mx = 0;
        for (int j = n-1; j; j--) {
            int i = queries[j];
            s[i] = arr[i];
            if (i && s[find(i-1)]) merge(i, i-1);
            if (i < n-1 && s[find(i+1)]) merge(i, i+1);
            mx= max(mx, s[find(i)]);
            res[j-1] = mx;
        }
        return res;
    }

    int find(int x) {
        if (x == p[x]) return x;
        return p[x] = find(p[x]);
    }

    void merge(int x, int y) {
        x = find(x); y = find(y);
        p[y] = p[x];
        s[x] += s[y];
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    Solution sol;
    vector<int> arr{1,2,5,6,1};
    vector<int> q{0,3,2,4,1};
    vector<ll> ans = sol.maximumSegementSum(arr, q);
    for (auto& x : ans) {
        cout << x << ' ';
    }
    cout << '\n';
    return 0;   
}