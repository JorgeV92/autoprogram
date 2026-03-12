#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n{};
    cin >> n;
    using i64 = long long;
    vector<i64> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    auto dfs = [&](auto&& dfs, int ii, i64 sum1, i64 sum2) -> i64 {
        if (ii == n) {
            return abs(sum1 - sum2);
        }
        i64 first{ dfs(dfs ,ii+1, sum1+A[ii], sum2)};
        i64 second { dfs(dfs, ii+1, sum1, sum2+A[ii])};
        return min(first, second);
    };

    cout << dfs(dfs, 0, 0, 0) << endl;

    return 0;
}