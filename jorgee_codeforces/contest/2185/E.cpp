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
        int n, m,  k;
        cin >> n >> m >> k;
        vector<ll> A(n);
        FOR(i,0,n) {
            cin >> A[i];
        }
        vector<ll> B(m);
        FOR(i,0,m) {
            cin >> B[i];
        }
        string s;
        cin >> s;
        sort(B.begin(), B.end());
        vector<vector<int>> die_at_pos(k+2);
        vector<vector<int>> die_at_neg(k+2);

        FOR(i,0,n) {
            auto it = lower_bound(all(B), A[i]);
            if (it != B.end()) {
                ll dist = *it - A[i];
                if (dist <= k && dist > 0) {
                    die_at_pos[dist].push_back(i);
                }
            }

            if (it != B.end()) {
                ll dist = A[i] - *prev(it);
                if (dist <= k && dist > 0) {
                    die_at_neg[dist].push_back(i);
                }
            }
        }

        int alive = n;
        vector<bool> is_dead(n, false);
        int curr_shift = 0;
        int max_shift = 0;
        int min_shift = 0;
        
        for (char c : s) {
            if (c == 'L') {
                curr_shift--;
            } else {
                curr_shift++;
            }

            if (curr_shift > max_shift) {
                max_shift = curr_shift;
                if (max_shift <= k) {
                    for (int id : die_at_pos[max_shift]) {
                        if (!is_dead[id]) {
                            is_dead[id] = true;
                            alive--;
                        }
                    }
                }
            }

            if (curr_shift < min_shift) {
                min_shift = curr_shift;
                int dist = -min_shift;
                if (dist <= k) {
                    for (int id : die_at_neg[dist]) {
                        if (!is_dead[id]) {
                            is_dead[id] = true;
                            alive--;
                        }
                    }
                }
            }
            cout << alive << " ";
        }
        cout << '\n';

    }

    return 0;
}