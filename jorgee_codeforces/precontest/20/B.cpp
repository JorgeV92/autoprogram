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
#include <iomanip>

using namespace std;

#define OUT(x) cout << fixed << setprecision(10) << x << '\n'
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
template<typename T> T sqr(const T& c) {return c*c;}

using ll = long long;
using pii = pair<int,int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c;
    cin >> a >> b >> c;
    double ra = a, rb = b, rc = c;
    if (a == 0) {
        if (b ==0) {
            if (c==0) 
                OUT(-1);
            else OUT(0);
        } else {
            OUT(1);
            OUT(-rc/rb);
        }
    } else {
        ll D = sqr(ll(b))-4*ll(a)*ll(c);
        if (D < 0) {
            OUT(0);
        } else if (D == 0) {
            OUT(1);
            OUT(-rb/(2*ra));
        } else {
            OUT(2);
            double x1 = (-b - sqrt(double(D))) / (2*ra);
            double x2 = (-b + sqrt(double(D))) / (2*ra);
            cout << min(x1,x2) << '\n' << max(x1, x2) << '\n';
        }
    }

    return 0;
}