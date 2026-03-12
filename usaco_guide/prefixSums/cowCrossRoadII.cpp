#include <iostream>
#include <vector>

using namespace std; 

constexpr int N = 100009;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, b;
    cin >> n >> k >> b;
    vector<int> A(n);
    for (int i = 0; i < b; i++) {
        int x;
        cin >> x;
        A[x-1] += 1;
    }

    vector<int> pre(n+1);
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i-1] + A[i-1];
    }

    int mn = n;
    for (int i = 0; i < n-k; i++) {
        mn = min(mn, pre[i+k] - pre[i]);
    }
    cout << mn << endl;
    
    return 0;
}