#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin  >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i <n; i++) {
            cin >> a[i];
        }
        vector<int> blockend(n);
        vector<int> sameValueRunEnd(n);
        for (int i = n-1; i >= 0; i--) {
            if (i + 1 < n && a[i+1] == a[i] + 1) {
                blockend[i] = sameValueRunEnd[i+1];
            } else {
                blockend[i] = i + 1;
            }
            if (blockend[i] < n && a[blockend[i]] == a[i]) {
                sameValueRunEnd[i] = sameValueRunEnd[blockend[i]];
            } else {
                sameValueRunEnd[i] = blockend[i];
            }
        }
        int minlen = 0;
        int pos = 0;
        while (pos < n) {
            minlen++;
            pos = blockend[pos];
        }
        cout << minlen << '\n';
    }
    return 0;
}