#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

#define FOR(i,a,b) for(int i = (a); i < (b); i++)

ll dp[19][50][2][2]; // dp[pos][k][under][started]
string num;

void rest() {
    FOR(i,0,19) {
        FOR(j,0,50)  {
            FOR(k,0,2) {
                FOR(l,0,2) {
                    dp[i][j][k][l] = -1;
                }
            }
        }
    }
}

ll solve_dp(int pos, int k, bool under, bool started, int targ, int targ2) {
    if (pos == num.size()) {
        if (!started) { return 0; }
        if (targ != -1) {
            if (k == 20) {
                return 1;
            } else {
                return 0;
            }
        }

        if (k >= 20) {
            return 1;
        } else {
            return 0;
        }
    }

    if (dp[pos][k][under][started] != -1) {
        return dp[pos][k][under][started];
    }

    ll ans = 0;
    for (int i = 0; i <= 9; i++) {
        int digit_diff = num[pos] - '0';
        if (!under && i > digit_diff) { 
            break; 
        }

        bool is_under = under;
        if (i < digit_diff) {
            is_under = true;
        }

        bool is_started = started || i != 0;

        if (is_started && targ2 != -1 && i != targ && i != targ2) {
            continue;
        }

        int new_k = k;
        if (is_started) {
            if (targ == i) {
                new_k = k + 1;
            } else {
                new_k = k - 1;
            }
        } 
        ans += solve_dp(pos+1, new_k, is_under, is_started, targ, targ2);
    }
    return dp[pos][k][under][started] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}
