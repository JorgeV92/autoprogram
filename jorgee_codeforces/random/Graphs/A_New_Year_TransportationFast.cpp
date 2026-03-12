#include <iostream>
#include <vector>

using namespace std; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t;
    cin >> n >> t;

    vector<int> a(n+1);
    for (int i = 1; i < n; i++) {
        cin >> a[i];
    }

    int p = 1;
    while (p < t) {
        p += a[p];
    }

    if (p == t) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}