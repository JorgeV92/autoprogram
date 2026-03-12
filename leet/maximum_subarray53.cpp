#include <iostream>
#include <vector>

using namespace std;

int maxSubarray(vector<int>& a) {
    int n = a.size();
    vector<int> L(n);
    for (int i = 0; i < n; i++) {
        L[i] = (i && L[i-1] > 0 ? L[i-1] : 0) + a[i];
    }
    return *max_element(L.begin(), L.end());
}

int maxSubarrayKaden(vector<int>& a) {
    int n = a.size();
    int curr = a[0];
    int mx = a[0];

    for (int i = 1; i < n; i++) {
        curr = max(a[i], curr + a[i]);
        mx = max(mx, curr);
    }
    return mx;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}