#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

void run() {
    ll n, h, k;
    std::cin >> n >> h >> k;
    std::vector<ll> a(n);
    std::vector<ll> prefix(n);
    for (int i = 0;i < n; i++) {
        std::cin >> a[i];
        prefix[i] = a[i];
        if (i - 1 >= 0)
            prefix[i] += prefix[i-1];
    }
    ll sum = prefix[n-1];
    ll lst = (h-1) / sum;
    ll time = n * lst + k * lst;
    h -= lst * sum;
    if (h <= 0) {
        std::cout << time << "\n";
        return;
    }
    std::vector<ll> mx_from_right(n+1, 0);
    mx_from_right[n-1] = a[n-1];
    for (int i = n-2; ~i; i--) {
        mx_from_right[i] = std::max(mx_from_right[i+1], a[i]);
    }
    ll mn_from_left  = a[0];
    for (int i = 0; i < n; i++) {
        mn_from_left = std::min(mn_from_left, a[i]);
        ll currsum = prefix[i] - mn_from_left + mx_from_right[i+1];
        if (h <= currsum || h <= prefix[i]) {
            std::cout << time + i + 1 << "\n";
            return;
        }
    }
}

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    int tt;
    std::cin >> tt;
    while (tt--) {
        run();
    }
    return 0;   
}