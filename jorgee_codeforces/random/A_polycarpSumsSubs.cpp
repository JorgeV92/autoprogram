#include <iostream>
#include <vector>

using namespace std;

void solve() {
    vector<int> b(7);
    for (int i = 0; i < 7; i++) {
        cin >> b[i];
    }
    cout << b[0] << " " << b[1] << " " << b[6] - b[0] - b[1] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
    return 0;
}