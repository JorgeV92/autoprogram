#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> A(n);
    for (int i = 0; i < n; i++) 
        cin >> A[i];

    sort(A.begin(), A.end());

    auto f = [&](int x) {
        ll ops = 0;
        for (int i = (n-1)/2; i < n; i++) {
            ops += max(0, x-A[i]);
        }
        return ops <= k;
    };

    int l = 0, r = 2e9;
    while (l < r) {
        int m = l + (r-l+1) / 2;
        if (f(m)) {
            l = m;
        } else {
            r = m -1;
        }
    }

    cout << l << endl;

    return 0;
}