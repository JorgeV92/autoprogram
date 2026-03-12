#include <iostream>
#include <vector>

using namespace std; 

using i64 = long long;

constexpr int MAXN = 50009;
i64 prefix[MAXN];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int x; 
        cin >> x;
        prefix[i] = (prefix[i-1] + x) % 7;
    }

    vector<int> idx(7, -1);
    int mx = 0;
    for (int i = 0; i <= n; i++) {
        if (idx[prefix[i]] == -1) {
            idx[prefix[i]] = i;
        } else {
            mx = max(mx, i - idx[prefix[i]]);
        }
    }
    cout << mx << endl;
    return 0;   
}