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
#define all(x) (x).begin(), (x).end()
#define FOR(i,a,b) for(int i = (a); i < (b); i++) 
#define FORE(i,a,b) for(int i = (a); i <= (b); i++)
#define ROF(i,a,b) for(int i = (a); i >= (b); i--)

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return false;}
template<class T> inline bool chmin(T& a, T b) { if ( a > b) { a = b; return 1;} return false;}

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string s, t;
        cin >> s >> t;
        vector<int> frq(26);
        FOR(i,0,t.size()) {
            frq[t[i]-'A']++;
        }

        ROF(i,s.size()-1,0) {
            if (frq[s[i]-'A'] > 0) {
                frq[s[i]-'A']--;
            } else {
                s[i] = '.';
            }
        }

        string res = "";
        FOR(i,0,s.size()) {
            if(s[i] != '.') 
                res += s[i];
        }

        if ( res == t) {
            OUT("YES");
        } else {
            OUT("NO");
        }
    }
    return 0;
}