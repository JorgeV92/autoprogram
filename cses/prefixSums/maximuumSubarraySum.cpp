#include <iostream>
#include <vector>

using namespace std; 

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    i64 sum = a[0];
    i64 mx = a[0];
    for (int i = 1; i < n; i++) {
        sum = max((i64)a[i], sum + (i64)a[i]);
        mx = max(mx, sum);
    }
    cout << mx << endl;

    return 0;
}