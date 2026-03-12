#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m, d;
        cin >> n >> m >> d;
        int total = d/ m;
        total++;
        cout << (n + total -1) /total << "\n";
    }
    return 0;
}