#include <iostream>
#include <vector>
#include <numeric>  

using namespace std;

const int MAX_SUM = 100005;

bool dp[MAX_SUM];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int X = accumulate(a.begin(), a.end(), 0);

    dp[0] = true;

    for (int c : a) {
        for (int s = X; s >= c; s--) {
            dp[s] = dp[s] || dp[s -c];
        }
    }

    vector<int> ans;
    for (int i = 1; i <= X; i++) {
        if (dp[i]) {
            ans.push_back(i);
        }
    }
    cout << ans.size() << endl;
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}