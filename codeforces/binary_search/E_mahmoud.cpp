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

int N, M, Q;
int a[100005], b[100005];
ll sb[2][100005], sumA, SB[100005];
set<ll> S;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    scanf("%d%d%d", &N, &M, &Q);
    FORE(i,1,N) {
        scanf("%d", a + i);
        if (i & 1) {
            sumA += a[i];
        } else {
            sumA -= a[i];
        }
    }
    FORE(i,1,M) {
        scanf("%d", b + i);
        sb[0][i] = sb[0][i-1];
        sb[1][i] = sb[1][i-1];
        sb[i&1][i] += b[i];
    }
    FORE(i,0,M-N) {
        SB[i] = sb[0][i+N] - sb[0][i] - sb[1][i+N] + sb[1][i];
        if (!(i&1)) 
            SB[i] = -SB[i];
        S.insert(SB[i]);
    }

    auto Qry = [&]() {
        auto it = S.lower_bound(sumA);
        if (it == S.end()) 
            return sumA - *prev(it);
        ll tmp = *it - sumA;
        return min(tmp, (it == S.begin() ? 1LL << 60 : sumA - *prev(it)));
    };

    printf("%lld\n", Qry());
    while (Q--) {
        int l, r , w;
        scanf("%d%d%d", &l, &r, &w);
        if ((l+r) % 2 == 0) {
            if (l&1) {
                sumA += w;
            } else {
                sumA -= w;
            }
        }
        printf("%lld\n", Qry());
    }
    return 0;
}