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
        int n;
        cin >> n;
        vector<int> A(n);
        FOR(i,0,n) {
            cin >> A[i];
        }
        int cnt = 0;
        ROF(i,n-2,0) {
            while (A[i] >= A[i+1] && A[i] > 0) {
                A[i] /= 2;
                cnt++;
            }
            if (A[i] == A[i+1]) {
                OUT(-1);
                goto end;
            } 
        }
        OUT(cnt);
    end:;
    }
    return 0;
}