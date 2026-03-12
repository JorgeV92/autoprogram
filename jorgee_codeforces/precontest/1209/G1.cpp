#include <iostream>
#include <vector>

using namespace std;

constexpr int M = 200001;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    vector<int> right(M);
    vector<int> frq(M);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        --a[i];
        right[a[i]] = i;
        frq[a[i]]++;
    }

    int total = n;
    for (int i = 0; i < n; i++) {
        int mx = frq[a[i]];
        int y = right[a[i]];
        for (int j = i+1; j <= y; j++) {
            y = max(y, right[a[j]]);
            mx = max(mx, frq[a[j]]);
        }
        total -= mx;
        i = y;
    }    

    cout << total << endl;

    return 0;
}