#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>
#include <algorithm>
#include <functional>
#include <cassert>

template<typename T, class F = std::function<T(const T&, const T&)>>
class SpareTable {
public:
    int n;
    std::vector<std::vector<T>> st;
    F func;

    SpareTable(const std::vector<T>& a, const F& f) : func(f) {
        n = static_cast<int>(a.size());
        int max_log = 32 - __builtin_clz(n);
        st.resize(max_log);
        st[0] = a;
        for (int j = 1; j < max_log; j++) {
            st[j].resize(n-(1 << j) + 1);
            for (int i = 0; i <= n - (1 << j); i++) {
                st[j][i] = func(st[j-1][i], st[j-1][i + (1 << (j-1))]);
            }
        }
    }

    T get(int from, int to) const {
        assert(0 <= from && from <= to && to <= n-1);
        int lg = 32 - __builtin_clz(to-from + 1) - 1;
        return func(st[lg][from], st[lg][to - (1 << lg) + 1]);
    }
};


int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    int tt;
    std::cin >> tt;
    while (tt--) {
        int n;
        std::cin >> n;
        std::vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
        }
        std::vector<long long> pref(n+1);
        for (int i = 0; i < n; i++) {
            pref[i+1] = a[i] + pref[i];
        }
        std::vector<int> b(n);
        std::iota(b.begin(), b.end(), 0);
        SpareTable<int> sa(b, [&](int i, int j) { return a[i] > a[j] ? i : j; });
        SpareTable<long long> smin(pref, [&](long long i, long long j) { return std::min(i, j); });
        SpareTable<long long> smax(pref, [&](long long i, long long j) { return std::max(i, j); });
        bool ok = true;
        std::function<void(int,int)> dfs = [&](int l, int r) {
            if (l > r) 
                return;
            int x = sa.get(l, r);
            long long mn = smin.get(l, x);
            long long mx = smax.get(x+1, r+1);
            if (a[x] < mx - mn) {
                ok = false;
            }
            dfs(l, x-1);
            dfs(x+1, r);
        };

        dfs(0, n-1);
        std::cout << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}