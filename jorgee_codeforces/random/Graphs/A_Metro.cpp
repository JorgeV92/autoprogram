#include <iostream>
#include <vector>

using namespace std; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t;
    cin >> n >> t;
    t--;

    vector<int> a(n), b(n);
    for (int i = 0 ; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    if (a[0] == 0) {
        cout << "NO\n";
        return 0;
    } 

    if (a[t] == 1) {
        cout << "YES\n";
        return 0;
    }

    if (b[t] == 1) {
        for (int k = t+1; k < n; k++) {
            if (a[k] == 1 && b[k] == 1) {
                cout << "YES\n";
                return 0;
            }
        }
    }

    cout << "NO\n";


    return 0;
}
