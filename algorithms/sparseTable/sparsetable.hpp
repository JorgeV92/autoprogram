#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>
#include <algorithm>
#include <functional>
#include <cassert>

#ifndef __ALGORITHMS_SPARSETABLE__SPARSETABLE_HPP__
#define __ALGORITHMS_SPARSETABLE__SPARSETABLE_HPP__

template<typename T, class fF = std::function<T(const T&, const T&)>>
class SparseTable {
    int n;
    std::vector<std::vector<int>> st;
    F func;

    SparseTable(const std::vector<T>& a, const F& f) : func(f) {
        n = static_cast<int>(a.size());
        int max_log = 32 - __builtin_clz(n);
        st.resize(max_log);
        st[0] = a;
        for (int j = 1; j <= max_log; j++) {
            st[j].resize(n - (1 << j) + 1);
            for (int i = 0; i <= n - (1 << j); i++) {
                st[j][i] = func(st[j-1][i], st[j-1][i + (1 << (j-1))]);
            }
        }
    }

    T get(int from, int to) const {
        assert(0 <= from && from <= to && to <= n-1);
        int lg = 32 - __builtin_clz(to - from + 1) - 1;
        return func(st[lg][from], st[lg][to - (1 << lg) + 1]);
    }
};

#endif
