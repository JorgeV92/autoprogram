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
#define FORE(i,a,b) for(i = (a); i <= (b); i++)
#define ROF(i,a,b) for(int i = (a); i >= (b); i--)

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return false;}
template<class T> inline bool chmin(T& a, T b) { if ( a > b) { a = b; return 1;} return false;}

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    string s;
    cin >> q >> s;

    vector<vector<bool>> dp(q, vector<bool>(q));
    
    string t;
    t.reserve(q);
    ll total =0;
    vector<int> end;
    end.reserve(q);
    int m =0;

    for (int ii = 0; ii < q; ii++) {
        char c = s[ii];
        if (c == '-') {
            m--;
            t.pop_back();
            total -= end.back();
            end.pop_back();
        } else {
            t.push_back(c);
            int j = m;
            m++;
            int add = 0;
            for (int i =j; i>= 0; i--) {
                if (i == j) {
                    dp[i][j] = 1;
                } else if (i + 1 == j) {
                    dp[i][j] = (t[i] == t[j]);
                } else {
                    dp[i][j] = (t[i] == t[j]) && dp[i+1][j-1];
                }
                add += dp[i][j];
            } 
            end.push_back(add);
            total += add;
        }
        cout << total << ' ';
    }
    cout << '\n';
    return 0;
}