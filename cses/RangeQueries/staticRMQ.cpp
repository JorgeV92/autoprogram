#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

const int maxn = 200006;
const int max_lg = 32 - __builtin_clz(maxn);
int st[max_lg][maxn];
int arr[maxn];
int n;

void build() {   
    std::copy(arr, arr+n, st[0]);
    for (int j = 1; j < max_lg; j++) {
        for (int i = 0; i <= n - (1 << j); i++) {
            st[j][i] = std::min(st[j-1][i], st[j-1][i + (1 << (j-1))]);
        }
    }
}

int get(int from, int to) {
    assert(0 <= from && from <= to && to <= n-1);
    int lg = 32 - __builtin_clz(to - from + 1) -1;
    return std::min(st[lg][from], st[lg][to - (1 << lg) + 1]);
} 

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    int q;
    std::cin >> n >> q;
    for (int i = 0; i< n; i++) {
        std::cin >> arr[i];
    }

    build();

    while (q--) {
        int l, r;
        std::cin >> l >> r;
        l--, r--;
        std::cout << get(l, r) << "\n";
    }
    return 0;
}