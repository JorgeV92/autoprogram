#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

void solve() {
    string s, t;
    cin >> s >> t;
    map<char, int> cs, ct;
    for (int i = 0; i < s.size(); i++) {
        cs[s[i]]++;
    }
    for (int i = 0; i < t.size(); i++) {
        ct[t[i]]++;
    }
    for (const auto&[k, v] : cs) {
        if (!ct.count(k) || ct[k] < v) {
            cout << "Impossible\n";
            return;
        }
    }
    vector<char> t_prime;
    for (const auto& [ch, cnt] : ct) {
        int need = cs.count(ch) ? cs[ch] : 0;
        int more = cnt - need;
        for (int i = 0; i < more; i++) {
            t_prime.push_back(ch);
        }
    }

    sort(t_prime.begin(), t_prime.end());
    string ans;
    int i = 0;
    int j = 0;

    while (i < s.size() && j < t_prime.size()) {
        if (s[i] <= t_prime[j]) {
            ans += s[i++];
        } else {
            ans += t_prime[j++];
        }
    }
    while (i < s.size()) ans += s[i++];
    while (j < t_prime.size()) ans += t_prime[j++];

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