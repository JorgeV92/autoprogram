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
#include <cstdio>
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

    int tt;
    cin >> tt;
    while (tt--) {
        int n; 
        cin >> n;
        vector<int> p(n);   
        FOR(i,0,n) {
            cin >> p[i];
        }
        vector<int> pos(n);
        pos[n-1] = n-1;
        ROF(i, n-2, 0) {
            if (p[i] > p[pos[i+1]]) {
                pos[i] = i;
            } else {
                pos[i] = pos[i+1];
            }
        }
        int l = -1, r = -1;
        FOR(i,0,n) {
            if (p[i] != p[pos[i]]) {
                l = i;
                r = pos[i];
                break;
            }
        }
        if (l != -1) {
            reverse(p.begin() + l, p.begin() + r + 1);
        } 
        FOR(i,0,n) {
            cout << p[i] << ' ';
        }
        cout << '\n';

    }
    return 0;
}