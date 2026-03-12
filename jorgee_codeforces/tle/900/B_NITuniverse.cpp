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
        int l = 0, r = n-1;
        int zeros = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x == 0 ){
                zeros++;
            }
            A[i] = x;
        } 
        bool found =false;
        while (A[l] == 0) 
            l++;
        while (A[r] == 0)
            r--;
        for (int i = l; i <= r; i++) {
            if (A[i] == 0) {
                found = true;
                break;
            }
        }

        if (zeros == n) {
            OUT(0);
        } else if (!found) {
            OUT(1);
        } else {
            OUT(2);
        }
    }

    return 0;
}