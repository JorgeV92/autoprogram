#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

const string subseq[] = {"00", "25", "50", "75"};
const int inf = 100;

int solve(string& s, string& t) {
    int sptr = s.length() - 1;
    int ans = 0;
    while (sptr >= 0 && s[sptr] != t[1]) {
        sptr--; 
        ans++;
    }
    if (sptr < 0) return inf;
    sptr--;
    while (sptr >= 0 && s[sptr] != t[0]) {
        sptr--;
        ans++;
    }
    return sptr < 0 ? inf : ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        string n;
        cin >> n;
        int ans = inf;
        for (auto e : subseq) {
            ans = min(ans, solve(n, e));
        }
        cout << ans << '\n';

    }
    return 0;
}