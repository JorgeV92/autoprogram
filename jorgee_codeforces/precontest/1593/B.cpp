#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int inf = 1e9;

const string subseqs[] = {"00", "25", "50", "75" };

int solve(const string& s, const string& t) {
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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        string n;
        cin >> n;
        int ans = inf;
        for (const auto& e : subseqs) {
            solve(n, e);
        }
    }

    return 0;
}