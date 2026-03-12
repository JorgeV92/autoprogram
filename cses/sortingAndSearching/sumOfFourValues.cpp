#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    using pii = pair<int,int>;
    vector<pii> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++) {
        for (int j = i +1; j < n; j++) {
            int l = j+1;
            int r = n-1;
            while (l < r) {
                int sum = a[i].first+a[j].first+a[l].first+a[r].first;
                if (sum == x) {
                    cout << a[i].second+1 << " "
                        << a[j].second+1 << " "
                        << a[l].second+1 << " "
                        << a[r].second+1 << "\n";
                        return 0;
                } else if (sum < x) {
                    l++; 
                } else {
                    r--;
                }
            }
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}