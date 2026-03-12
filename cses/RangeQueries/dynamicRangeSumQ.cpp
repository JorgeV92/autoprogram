#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;


struct segtree {
    vector<int64_t> tree, A;
    void init(int n, vector<int>& arr) {
        A = vector<int64_t>(arr.begin(), arr.end());
        tree = vector<int64_t>(n*4);
        build(1, 0, n-1);
    }

    void build(int at, int at_l, int at_r) {
        if (at_l == at_r) {
            tree[at] = A[at_l];
        } else {
            int at_m = (at_l + at_r) >> 1;
            build(at<<1, at_l, at_m);
            build(at<<1|1, at_m+1, at_r);
            tree[at] = tree[at<<1] + tree[at<<1|1];
        }
    }

    void update(int idx, int val, int at, int at_l, int at_r) {
        if (at_l == at_r) {
            tree[at] = val;
        } else {
            int at_m = (at_l + at_r) >> 1;
            if (idx <= at_m) {
                update(idx, val, at<<1, at_l, at_m);
            } else {
                update(idx, val, at<<1|1, at_m+1, at_r);
            }
            tree[at] = tree[at<<1] + tree[at<<1|1]; 
        }
    }

    int64_t rangesum(int start, int end, int at, int at_l, int at_r) {
        if (at_r < start || end < at_l) return 0;
        if (start <= at_l && at_r <= end) return tree[at];
        int at_m = (at_l + at_r) >> 1;
        int64_t l = rangesum(start, end, at<<1, at_l, at_m);
        int64_t r = rangesum(start, end, at<<1|1, at_m+1, at_r);
        return l + r;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    segtree sgtree;
    sgtree.init(n, arr);

    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int k, u;
            cin >> k >> u;
            k--;
            sgtree.update(k, u, 1, 0, n-1);
        } else {
            int a, b;
            cin >> a >> b;
            a--; b--;
            cout << sgtree.rangesum(a, b, 1, 0, n-1) << endl;
        }
    }

    return 0;
}