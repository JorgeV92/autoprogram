#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<string> grid(2);
    for (int i = 0; i < 2; i++) {
        cin >> grid[i];
    }

    for (int i = 0 ; i < n; i++) {
        if (grid[0][i] == '1' && grid[1][i] == '1') {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--){
        solve();
    }

    return 0;
}