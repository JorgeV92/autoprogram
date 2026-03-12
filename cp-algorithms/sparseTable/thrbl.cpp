#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>
#include <algorithm>
#include <functional>
#include <cassert>


template<typename T, class F = std::function<T(const T&, const T&)>>
class SparseTable {
    int n;
    std::vector<std::vector<T>> st;
    F func;
public:
    SparseTable(const std::vector<T>& a, const F& f) : func(f) {
        n = static_cast<int>(a.size());
        int max_lg = 32 - __builtin_clz(n);
        st.resize(max_lg);
        st[0] = a;
        for (int j = 1; j < max_lg; j++) {
            st[j].resize(n - (1 << j) + 1);
            for (int i = 0; i <= n - (1 << j); i++) {
                st[j][i] = func(st[j-1][i], st[j][i + (1 << (j-1))]);
            }
        }
    }

    T get(int from, int to) {
        assert(0 <= from && from <= to && to <= n-1);
        int lg = 32 - __builtin_clz(to - from + 1) - 1;
        return func(st[lg][from], st[lg][to - (1 << lg) + 1]);
    }
};

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    SparseTable<int> sp(a, [&](int i, int j) { return std::max(i, j); });
    int ans = 0;
    while (m--) {
        int A, B;
        std::cin >> A >> B;
        --A; --B;
        if (A  > B) std::swap(A, B);
        if (abs(A-B) <= 1) ans++;
        else {
            int mxe = sp.get(A+1, B-1);
            if (mxe <= a[A]) ans++;
        }
    }
    std::cout << ans << "\n";
    return 0;
}