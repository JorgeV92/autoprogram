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

    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> A(n);
        for (int& i : A) {
            cin >> i;
        }

        auto get_value = [&]() {
            ll curr = 0;
            ll mx = -1e9;
            for (int x : A) {
                if (x > mx) {
                    mx = x;
                } 
                curr += mx;
            }
            return curr;
        };

        ll ans = get_value();
        FOR(i,0,n) {
            FOR(j,i+1,n) {
                swap(A[i],A[j]);
                chmax(ans,get_value());
                swap(A[i],A[j]);
            }
        }
        OUT(ans);
    }
    return 0;
}