#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std; 

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, X;
    cin >> n >> X;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    vector<ll> L, R;

    auto dfs = [&](auto&&dfs, int l, int r, ll sum, vector<ll>& S) {
        if (l > r) {
            S.push_back(sum);
            return;
        }
        dfs(dfs, l+1, r, sum+A[l], S);
        dfs(dfs, l+1, r ,sum, S);
    };

    dfs(dfs, 0, n/2-1, 0, L);
    dfs(dfs, n/2, n-1, 0, R);
    sort(L.begin(), L.end());
    sort(R.begin(), R.end());

    // or 
    auto subsets = [&](int l, int r, vector<int>& Y) {
        int len = r - l + 1;
        for (int m = 0; m < (1 << len); ++m) {
            ll sum = 0;
            for (int j = 0; j < len; j++) {
                if ((1 << j) & m) sum += A[l + j];
            }
            Y.push_back(sum);
        }
        sort(Y.begin(), Y.end());
    };

    // subset(0, n/2-1, L);
    // subset(n/2, n-1, R);

    // or 
    /*
        // Returns a list of all subset sums, in sorted order.
        vector<ll> subsets(vector<int> x) {
            int n = x.size();
            vector<ll> ret(1 << n);
            for (int m = 0; m < (1 << n); ++m) {
                for (int j = 0; j < n; ++j) {
                    if ((1 << j) & m) ret[m] += x[j];
                }
            }
            sort(ret.begin(), ret.end());
            return ret;
        }

        auto a = subsets(vector<int>(t.begin(), t.begin() + n / 2));
        auto b = subsets(vector<int>(t.begin() + n / 2, t.end()));
    */  

    ll ans = 0;
    for (ll i : L) {
        auto it_low = lower_bound(R.begin(), R.end(), X-i);
        auto it_high = upper_bound(R.begin(), R.end(), X-i);
        ans += it_high - it_low;
    }

    cout << ans << endl;
    
    return 0;
}