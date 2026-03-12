#include <iostream>
#include <vector>
#include <string>

using namespace std;

constexpr int ALP = 26;

void solve() {
    string p, h;
    cin >> p >> h;

    vector<int> cntp(ALP), wind(ALP);
    vector<bool> eq(ALP);
    int sum = 0;
    
    auto change = [&cntp, &wind, &eq, &sum](int c, int val) {
        sum -= eq[c];
        wind[c] += val;
        eq[c] = (cntp[c] == wind[c]);
        sum += eq[c];
    };

    for (int i = 0; i < p.size(); i++) {
        cntp[p[i]-'a']++;
    }
    for (int i = 0; i < ALP; i++) {
        eq[i] = (cntp[i] == wind[i]);
        sum += eq[i];
    }

    int m = p.size();
    int n = h.size();

    for (int i = 0; i < n; i++) {
        change(h[i]-'a', 1);
        if (i >= m) {
            change(h[i-m]-'a', -1);
        }
        if (sum == ALP) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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