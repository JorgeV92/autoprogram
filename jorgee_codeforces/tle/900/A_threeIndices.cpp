#include <iostream>
#include <vector>

using namespace std; 

void solve(){
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    for (int i = 1; i < n-1; i++) {
        if (p[i] > p[i-1] && p[i] > p[i+1]) {
            cout << "YES\n";
            cout << i-1 + 1 << ' ' << i +1 << ' ' << i+2 << '\n';
            return;
        }
    }  
    cout << "NO\n";  
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}