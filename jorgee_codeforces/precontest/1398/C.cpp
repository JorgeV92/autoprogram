#include <iostream>
#include <vector>
#include <map>

using namespace std; 

using i64 = long long;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> prefix(n+1);
    for (int i = 1; i <= n; i++) {
        int x = s[i-1] - '0';
        prefix[i] = prefix[i-1] + x;
    }
    
    map<int,i64> mp;
    for (int i = 0; i <= n; i++) {
        mp[prefix[i] - i]++;
    }

    i64 good = 0;
    for (const auto& [_, f] : mp) {
        good += f * (f-1) / 2;
    }
    cout << good << endl;
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