#include <iostream>
#include <vector>
#include <queue>

using namespace std; 

constexpr int N = 10005;
int C[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, T;
    cin >> n >> T;
    
    for (int i =0 ;i < n; i++) {
        cin >> C[i];
    }

    int l = 0, r = n;
    int K = n;

    while (l <= r) {
        int m = l + (r - l) / 2;
        int t = 0, j = 0;
        priority_queue<int,vector<int>,greater<int>> h;
        int sz = 0;
        while (sz < m && j < n) {
            h.push(C[j]);
            sz++; j++;
        }

        while (h.size()) {
            t += max(0, h.top() - t);
            h.pop();
            if (j < n) {
                h.push(C[j] + t);
                j++;
            }
        }

        if (t > T) {
            l = m + 1;
        } else {
            K = min(K, m);
            r = m - 1;
        }
    }

    cout << K << endl;
    return 0;
}