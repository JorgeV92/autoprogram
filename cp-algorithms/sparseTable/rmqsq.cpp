#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>
#include <algorithm>
#include <functional>
#include <cassert>

using namespace std;


const int maxn = 1000000 + 5;
const int max_lg = 32 - __builtin_clz(maxn);
int st[max_lg][maxn];
int a[maxn];
int n;

void init() {
    std::copy(a, a+n, st[0]);
    for (int j = 1; j < max_lg; j++) {
        for (int i = 0; i <= n - (1 << j); i++) {
            st[j][i] = min(st[j-1][i], st[j-1][i + (1 << (j-1))]);
        }
    }
}

int get(int from, int to) {
    assert(0 <= from && from <= to && to <= n-1);
    int lg = 32 - __builtin_clz(to - from + 1) - 1;
    return min(st[lg][from], st[lg][to - (1 << lg) + 1] );
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    init();

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << get(l ,r) << '\n';
    }

    return 0;
}
