#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n*2);
    for (int i = 0; i < n*2; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int ans = 1e9;
    for (int i = 0; i < 2*n; i++) {
        for (int j = i+1; j < 2*n; j++) {
            vector<int> tmp;
            for (int k = 0; k < 2*n; k++) {
                if (k != i && k != j) {
                    tmp.push_back(a[k]);
                }
            }

            int sum = 0;
            for (int k = 0; k < 2*n-2; k+=2) {
                sum += tmp[k+1] - tmp[k];
            }
            ans = min(ans, sum);
        }
    }

    cout << ans << endl;

    return 0;
}