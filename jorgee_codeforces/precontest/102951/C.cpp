#include <iostream>
#include <vector>

using namespace std; 

constexpr int N = 1e5 + 9;
int a[N], b[N], c[N], pos[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }

    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++) {
        c[i] = pos[b[i]];
    }

    vector<int> u;
    for (int i = 1; i<= n; i++) {
        auto it = lower_bound(u.begin(), u.end(), c[i]);
        if (it == u.end()) {
            u.push_back(c[i]); 
        } else {
            *it = c[i];
        }
    }

    cout << u.size() << endl;

    return 0;
}   