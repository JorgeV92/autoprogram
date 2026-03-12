#include <vector>

using namespace std;

struct segtree {
    int N; vector<int> tree, A; 
    void init(int n, vector<int>& arr) { 
        N = n;
        A = arr;
        tree = vector<int>(n*4); 
        build(1, 0, N-1);
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
    int rangesum(int start, int end, int at, int at_l, int at_r) {
        if (at_r < start || end < at_l) return 0;
        if (start <= at_l && at_r <= end) return tree[at];
        int at_m = (at_l + at_r) >> 1;
        int l = rangesum(start, end, at<<1, at_l, at_m);
        int r = rangesum(start, end, at<<1|1, at_m+1, at_r);
        return l + r;
    }
};