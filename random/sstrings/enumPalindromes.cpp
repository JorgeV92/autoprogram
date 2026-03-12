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

#define OUT(x) cout << x << '\n';
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
        ms = "@";
        org = string(s);
        for (char c : s) {
            ms += "#" + string(1,c);
        }
        ms += "#$";
        run();
    }

    void run() {
        int n = ms.size();
        p.assign(n,0);
        int l = 0, r = 0;
        for (int i = 1; i < n-1; i++)  {
            int mirro = l + r - i;
            if (i < r) {
                p[i] = min(r-i, p[mirro]);
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

    vector<int> allLPS() {
        int n = org.size();
        vector<int> out(2*n-1);
        for (int i = 0; i < 2*n-1; i++) {
            out[i] = p[i+2];
        }
        return out;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    cin >> s;

    Manacher ma;
    ma.init(s);
    
    vector<int> res = ma.allLPS();
    FOR(i,0,res.size()) {
        cout << res[i] << ' ';
    }
    cout << '\n';

    return 0;
}