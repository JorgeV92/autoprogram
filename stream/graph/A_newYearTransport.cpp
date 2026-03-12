#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, t;
    cin >> n >> t;
    vector<int> a(n+1);
    for (int i = 1; i < n; i++) cin >> a[i]; 
    int cur = 1;
    do {
        cur = cur + a[cur];
        if (cur == t) {
            cout << "YES\n";
            return 0;
        }
    } while (cur < n);
    cout << "NO\n";
    return 0;
}