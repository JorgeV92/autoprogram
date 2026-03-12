#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, d;
    cin >> n >> d;
    string a;
    cin >> a;
    

    // greedy
    int jumps = 0;
    int i = 0;
    while (i < n-1) {
        bool found = false;
        for (int j = d;  j >= 1; j--) {
            int t = i + j;
            if (t < n && a[t] == '1') {
                i = t;
                jumps++;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << jumps << endl;

    return 0;
}