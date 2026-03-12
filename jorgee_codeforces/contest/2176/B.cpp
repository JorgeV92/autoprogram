#include <iostream>
#include <vector>
#include <string>

using namespace std; 

void solve() {
    int n; 
    cin >> n;
    string s;
    cin >> s;

    vector<int> idx;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') 
            idx.push_back(i);
    } 

    if (idx.size() == n) {
        cout << 0 << endl;
        return;
    }
    int len = 0;
    for (int i = 0; i < idx.size()-1; i++) {
        len = max(len, idx[i+1] - idx[i] - 1);
    }
    len = max(len, (n+idx[0] - idx.back() - 1));
    cout << len << endl;
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