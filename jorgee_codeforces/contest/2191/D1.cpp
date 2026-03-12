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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> sufOpen(n+1,0);
        ROF(i,n-1,0) {
            sufOpen[i] = sufOpen[i+1] + (s[i] == '(' ? 1 : 0);
        }
        bool found = false;
        FOR(i,0,n-1) {
            if (s[i] == ')' && s[i+1] == '(') {
                if (sufOpen[i+2] > 0) {
                    found =true;
                    break;
                }
            }
        }
        if (found) {
            OUT(n-2);
        } else {
            OUT("-1");
        }
    }
    return 0;
}