#include <iostream>
#include <vector>

using namespace std; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int64_t> P(n+1);
    for (int i = 1; i <= n; i++) {
        P[i] = P[i-1] + arr[i-1];
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << P[b] - P[a-1] << endl;
    }
    return 0;
}