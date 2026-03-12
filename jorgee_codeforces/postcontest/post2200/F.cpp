#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cstdint>

using namespace std;

struct particle {
    int64_t x;
    int64_t y;
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<particle> a(n);
    for (int i = 0; i < n; i++) {
        int64_t x, y;
        cin >> x >> y;
        a[i] = {x, y};
    }

    vector<pair<int64_t, int64_t>> shop(m);
    for (int i = 0; i < m; i++) {
        int64_t x, y;
        cin >> x >> y;
        shop[i] = {x, y};
    }

    sort(a.begin(), a.end(), [&](const particle& p1, const particle& p2) {
        return p2.y < p1.y;
    });

    multiset<int64_t> keep;
    int64_t sumkeep = 0;
    int64_t bestWithoutShop = 0;

    vector<int64_t> pref(n+1, 0);
    int ptr = 0;
    for (int k = n; k >= 0; k--)  {
        while (ptr < n && a[ptr].y >= k) {
            keep.insert(a[ptr].x);
            sumkeep += a[ptr].x;
            ++ptr;
        }
        while ((int)keep.size() > k + 1) {
            auto it = keep.begin();
            sumkeep -= *it;
            keep.erase(it);
        }

        bestWithoutShop = max(bestWithoutShop, sumkeep);

        if ((int)keep.size() <= k) {
            pref[k] = sumkeep;
        } else {
            pref[k] = sumkeep - *keep.begin();
        }
    }
    
    for (int k = 1; k <= n; k++) {
        pref[k] = max(pref[k], pref[k-1]);
    }

    for (int i = 0; i < m; i++) {
        int64_t x = shop[i].first;
        int64_t y = shop[i].second;
        int64_t ans = max(bestWithoutShop, x + pref[y]);
        cout << ans << " ";
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}