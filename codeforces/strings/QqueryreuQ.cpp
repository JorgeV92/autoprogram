#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#include <string_view>

using namespace std;

#define OUT(x) cout << x << '\n'
#define OUTONE(x) cout << x << ' '
#define all(x) (x).begin(), (x).end()
#define FOR(i,a,b) for(int i = (a); i < (b); i++) 
#define FORE(i,a,b) for(i = (a); i <= (b); i++)
#define ROF(i,a,b) for(int i = (a); i >= (b); i--)

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return false;}
template<class T> inline bool chmin(T& a, T b) { if ( a > b) { a = b; return 1;} return false;}

using ll = long long;

struct Manacher {
    vector<int> p;
    string ms;
    string org;

    void init(string_view s) {
        int n= s.size();
        org = string(s);
        ms.clear();
        ms.reserve(2*n+3);
        ms.push_back('@');
        for (char c : s) {
            ms.push_back('#'); ms.push_back(c);
        }
        ms.push_back('#'); ms.push_back('$');
        gen();
    }

    void gen() {
        int n = ms.size();
        p.assign(n,0);
        int l =0, r = 0;
        for (int i= 1 ; i < n-1; i++) {
            int mirror = l + r -i;
            if (i < r) {
                p[i] = min(r-i, p[mirror]);
            }       
            while (ms[i+1+p[i]] == ms[i-1-p[i]]) {
                ++p[i];
            }
            if (i + p[i] > r) {
                l = i - p[i];
                r = i + p[i];
            }
        }
    }

    int getLongest(int cen, int odd) {
        int pos = 2 * cen + 2 + !odd;
        return p[pos];
    }

    ll count_pal_sunstrings() const {
        ll ans = 0;
        for (int i = 1; i < (int)ms.size() - 1; i++) {
            ans += (p[i] + 1) / 2;
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    string s;
    cin >> s;

    string t;
    t.reserve(q);

    Manacher ma;
    for (int i = 0; i < q; i++) {
        char c = s[i];
        if (c == '-') {
            t.pop_back();
        } else {
            t.push_back(c);
        }

        ma.init(t);
        ll ans = ma.count_pal_sunstrings();
        OUTONE(ans);
    }
    cout << '\n';


    return 0;
}