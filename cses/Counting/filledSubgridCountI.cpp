#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

#define ll long long

constexpr int N = 3005;
string grid[N];
ll dp_up[N][N];
ll dp_left[N][N];
ll dp_square[N][N];
ll res[26];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    for (int i= 0; i < n; i++) {
        cin >> grid[i];
    }
    for (int l = 0; l < k; l++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (grid[i-1][j-1] != 'A' + l) {
                    dp_up[i][j] = 0;
                    dp_left[i][j] = 0;
                    dp_square[i][j] = 0;
                    continue;
                }
                dp_up[i][j] = dp_up[i-1][j] + 1;
                dp_left[i][j]= dp_left[i][j-1] + 1;

                dp_square[i][j] = min({
                    dp_up[i-1][j],
                    dp_left[i][j-1],
                    dp_square[i-1][j-1]
                }) + 1;

                res[l] += dp_square[i][j]; 
            }
        }
    }
    for (int i = 0; i < k; i++) {
        cout << res[i] << endl;
    }

    return 0;
}