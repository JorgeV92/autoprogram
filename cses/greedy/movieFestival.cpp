#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int,int>> M(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        M[i] = {a, b};
    }

    sort(M.begin(), M.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
    });

    int curr_end = -1;
    int ans = 0;
    for (int i = 0 ;i < n; i++) {
        if (M[i].first >= curr_end) {
            curr_end = M[i].second;
            ans++;
        }
    }

    cout << ans << endl;


    return 0;
}