#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

#define ll long long

constexpr int N = 2e5 + 9;
int a[N], b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    sort(a, a+n);
    sort(b, b+m);

    int ans = 0;
    int i = 0, j = 0;

    while (i < n && j < m) {
        if (abs(a[i] - b[j]) <= k) {
            i++; j++; ans++;
        } else {
            if (a[i] - b[j] > k) {
                j++;
            } else {
                i++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}