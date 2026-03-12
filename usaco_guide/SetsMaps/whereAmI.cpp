#include <iostream>
#include <set>
#include <string>

using namespace std;
// O(n^3)
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    string t;
    cin >> t;

    int ans = 1;

    auto duplicates = [&](int len){
        set<string> X;
        for (int i = 0; i <= n-len; i++) {
            if (X.count(t.substr(i, len)) > 0) return true;
            X.insert(t.substr(i, len));
        }
        return false;
    };

    while (duplicates(ans)) 
        ans++;
    cout << ans << endl;

    return 0;
}