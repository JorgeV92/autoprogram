#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>
#include <algorithm>
#include <functional>
#include <cassert>
#include <iomanip>

using namespace std;

template<typename T, class F = function<T(const T&, const T&)>>
class SparseTable {
    int n;
    vector<vector<T>> st;
    F func;

public:
    SparseTable(const vector<T>& a, const F& f) : func(f) {
        n = static_cast<int>(a.size());
        int max_lg = 32 - __builtin_clz(n);
        st.resize(max_lg);
        st[0] = a;
        for (int j = 1; j < max_lg; j++) {
            st[j].resize(n - (1 << j) + 1);
            for (int i = 0; i <= n - (1 << j); i++) {
                st[j][i] = func(st[j-1][i], st[j-1][i + (1 << (j-1))]);
            }
        }
    }
    
    T get(int from, int to) {
        assert(0 <= from && from <= to && to <= n-1);
        int lg = 32 - __builtin_clz(to -from + 1) - 1;
        return func(st[lg][from], st[lg][to - (1 << lg) + 1]);
    }
};

int main() {
    ios::sync_with_stdio(0);  cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<int> pref_mx(n), suff_mx(n);
    pref_mx[0] = v[0];
    for (int i = 1; i <n; i++) {
        pref_mx[i] = max(pref_mx[i-1], v[i]);
    }
    suff_mx[n-1] = v[n-1];
    for (int i = n-2; ~i; i--) {
        suff_mx[i] = max(suff_mx[i+1], v[i]);
    }
    
    SparseTable<int> spmx(v, [&](int i, int j){ return max(i,j); });
    SparseTable<int> spmn(v, [&](int i, int j) { return min(i,j); });
    
    int q;
    cin >> q;
    cout << fixed << setprecision(1);
    while (q--) {
        int l, r;
        cin >> l >> r;
        int mn = spmn.get(l, r);
        int mx = spmx.get(l, r);
        double ans = (mn + mx) / 2.0;
        int out = -1;
        if (l > 0) out = max(out, pref_mx[l-1]);
        if (r+1 < n) out = max(out, suff_mx[r+1]);
        if (out != -1) 
            ans = max(ans, mn + (double)out);
        cout << ans << '\n';
    }
}
