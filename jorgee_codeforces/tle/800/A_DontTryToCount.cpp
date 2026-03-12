#include <iostream>
#include <vector>
#include <string>

using namespace std; 

void solve() {
    int n, m;
    cin >> n >> m;
    string x, s;
    cin >> x >> s;

    auto check = [&](const string& lx, const string& rs) {
        if (lx.size() < rs.size()) return false;
        for (int i = 0; i < lx.size() -rs.size() +1 ; i++) {
            if (lx.substr(i, rs.size()) == rs) {
                return true;
            }
        } 
        return false;
    };

    string X = x;
    int ans = -1;
    for (int i = 0; i <= 5; i++) {
        if (check(X, s)) {
            ans = i;
            break;
        }
        X += X;
    }   
    cout << ans << endl;
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