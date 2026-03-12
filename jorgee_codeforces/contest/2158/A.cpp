#include <iostream>
#include <vector>

using namespace std;

void solve(int N) {
    int y, r;
    cin >> y >> r;
    int suspended = 0;

    suspended += r;
    while (y >= 2) {
        suspended++;
        y -= 2;
    }
    if (suspended > N) {
        suspended = N;
    }
    cout << suspended << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        solve(n);
    }

    return 0;
}