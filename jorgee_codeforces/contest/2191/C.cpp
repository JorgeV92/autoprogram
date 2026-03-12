#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#include <string_view>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define OUT(x) cout << x << '\n'
#define all(x) (x).begin(), (x).end()
#define FOR(i,a,b) for(int i = (a); i < (b); i++) 
#define FORE(i,a,b) for(int i = (a); i <= (b); i++)
#define ROF(i,a,b) for(int i = (a); i >= (b); i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return false;}
template<class T> inline bool chmin(T& a, T b) { if ( a > b) { a = b; return 1;} return false;}

using ll = long long;
using pii = pair<int,int>;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (is_sorted(all(s))) {
        OUT("Bob");
        return;
    }
    OUT("Alice");
    int zeros = count(all(s), '0');
    vector<int>moves;
    FOR(i,0,n) {
        if (i < zeros) {
            if (s[i] == '1')
                moves.pb(i+1);
        } else {
            if (s[i] == '0')
                moves.pb(i+1);
        }
    }
    OUT(moves.size());
    FOR(i,0,moves.size()) {
        cout << moves[i] << ' ';
    }
    OUT('\n');
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>> t;
    while (t--) {
        solve();
    }
    return 0;
}