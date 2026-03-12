#include <iostream>
#include <vector>

using namespace std;

using vi = vector<int>;

struct DSU {
    vi e; void init(int N) { e = vi(N, -1); }
    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
    bool sameSet(int x, int y) { return get(x) == get(y); }
    int size(int x) { return -e[get(x)]; }
    bool unite(int x, int y) {
        x = get(x);
        y = get(y);
        if (x == y) return false;
        if (e[x] > e[y]) swap(x, y);
        e[x] += e[y];
        e[y] = x;
        return true;
    }
};

vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& q) {
    DSU D;
    D.init(n);

    auto isValid = [&](int a, int b) -> {
        return (nums[b] - nums[a]) <= maxDiff;
    };

    for (int i = 0; i < n; i++) {
        if (isValid(i, i+1)) {
            D.unite(i, i+1);
        }
    }
    
    vector<bool> ans(n, false);
    for (int i = 0; i < q.size(); i++) {
        ans[i] = D.sameSet(q[i][0], q[i][1]);
    } 

    return ans;
}

int main() {

    return 0;
}
