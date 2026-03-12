#include <iostream>
#include <vector>

using namespace std; 

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<i64> prefix(N+1);
    for (int i = 1; i <= N; i++) {
        int x;
        cin >> x;
        prefix[i] = prefix[i-1] + (i64)x;
    }

    while (Q--) {
        int l, r;
        cin >> l >> r;
        cout << prefix[r] - prefix[l] << endl;
    }

    return 0;
}