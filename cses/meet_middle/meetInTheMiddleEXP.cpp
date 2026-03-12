#include <iostream>
#include <vector>

using namespace std; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, X;
    cin >> n >> X;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    int cnt = 0;
    auto dfs = [&](auto&& dfs, int i, int sum) {
        if (sum == X) {
            cnt++;
            return;
        }
        if (i == n) return;
        dfs(dfs,i+1,sum+A[i]);
        dfs(dfs, i+1, sum);
    };

    dfs(dfs, 0, 0);
    cout << cnt << endl;
    return 0;
}