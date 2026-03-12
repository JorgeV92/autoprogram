#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (auto& el : a) cin >> el;
        vector<int> ord(n);
        iota(ord.begin(), ord.end(), 0);
        stable_sort(ord.begin(), ord.end(), [&](int i, int j) {
            return (a[i] - 1) % k > (a[j] - 1) % k;
        }) ;
        for (int i = 0; i < n; i++) {
            cout << ord[i] +1 << " \n"[i==n-1];
        }    
    }
    return 0;
}