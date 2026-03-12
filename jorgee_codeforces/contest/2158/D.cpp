#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define pii pair<int,int>

vector<pii> reduce (string& s) {
    int n = (int)s.size();
    vector<pii> op;
    int p = -1;
    for (int i = 0; i < n-1; i++) {
        if (s[i] == s[i+1]) p = i;
    }
    if (p == -1) {
        op.push_back({0,2});
        s[0] ^= 1; 
        s[1] ^= 1;
        p = 2;
    }

    char value = s[p+1];
    int L = p;
    int R = p + 1;

    while (R +1 < n) {
        if (s[R+1] != value) op.push_back({L, R});
        R++;
        value = s[R];
    }

    while (L) {
        if (s[L-1] != value) op.push_back({L,R});
        L--;
        value = s[L];
    }

    if (value == '1') op.push_back({0, n-1});
    return op;

}

void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;

    auto operations_s = reduce(s);
    auto operations_t = reduce(t);

    reverse(operations_t.begin(), operations_t.end());

    int moves = (int)operations_s.size() + (int)operations_t.size();
    cout << moves << endl;
    for (auto& [l, r] : operations_s) cout << l+1 << " " << r+1 << endl;
    for (auto& [l, r] : operations_t) cout << l+1 << " " << r+1 << endl;
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

/*
    01011
    10000

    10111
    10000
*/