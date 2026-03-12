#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    struct DSU {
        int n; vector<int> e; void init(int _n) { n = _n; e = vector<int>(n,-1); }
        int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
        int size(int x) { return -e[get(x)]; }
        bool unite(int x, int y) {
            x = get(x), y = get(y); if (x == y) return false;
            if (e[x] > e[y]) swap(x, y);
            e[x] += e[y]; e[y] = x;
            return true;
        }
    };
    int validSubarraySize(vector<int>& nums, int threshold) {
        int n = nums.size();
        using pii = pair<int,int>;
        vector<pii> arr(n);
        for (int i = 0 ;i < n; i++) {
            arr[i] = {nums[i], i};
        }
        sort(arr.begin(), arr.end());
        vector<bool> vis(n);
        DSU d;
        d.init(n);
        for (int j = n-1; ~j; j--) {
            int v = arr[j].first, i = arr[j].second;
            if (i && vis[i-1])
                d.unite(i, i-1);
            if (i < n-1 && vis[i+1])
                d.unite(i, i + 1);
            if (v > (threshold / d.size(i))) {
                return d.size(i);
            }
            vis[i] = true;
        }
        return -1;
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    return 0;
}