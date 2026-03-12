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
        vector<int> p(n+5);
        int ind = 1;
        for (int i = 1; i <= n; i++) 
            cin >> p[i];
        while (ind <= n && p[ind] == n - ind+1) ind++;
        int id = -1;
        for (int i = ind; i <= n; i++) 
            if (p[i] == n - ind + 1) id = i;
        for (int i = 1; i < ind; i++) cout << p[i] << ' ';
        if (id != -1) {
            for (int i = id; i >= ind; i--) cout << p[i] << ' ';
            for (int i = id + 1; i <= n; i++) cout << p[i] << ' ';
        }
        cout << '\n';
        
    }
    return 0;
}