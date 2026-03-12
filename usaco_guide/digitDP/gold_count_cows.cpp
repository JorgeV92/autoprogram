#include <iostream>
#include <vector>

using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)

vector<int> xlim, ylim, xvec, yvec;
int dp[40][3][3][2]; // [pos][ xcarry to pos ][ ycarry to pos ]
                     // [ suffix of x being formed is leq suffix of xlim ]

int highest_trit = 39;


namespace util {
    vector<int> dec_to_ternary(int d) {
        string ans = string(40, '0');
        while (d != 0) {
            int i = 1, pow = 0;
            while (i * 3 <= d) i *= 3; pow++;
            if (i * 2 <= d) i *= 2, ans[40 - pow -1] = '2';
            else ans[40 - pow - 1] = '1';
            d -= i;
        }
        vector<int> v;
        for (char c : ans) {
            v.push_back(c - '0');
        }
        return v;
    }
    int carry(int val, int& add) {
        if (val + add < 3) {
            int addcpy = add; add = 0;
            return val + addcpy;
        }
        val = (val + add) % 3, add = 1;
        return val;
    }

    void reset() {
        FOR(i,0 ,40) {
            FOR(j,0,3) {
                FOR(k,0,3) {
                    FOR(l,0,2) {
                        dp[i][j][k][l] = -1;
                    }
                }
            }
        }
    }
}

using namespace util;

int dfs(int pos, int carryX, int carryY, bool leq) {
    int cx = carryX, cy = carryY;
    int& state = dp[pos][carryX][carryY][leq];
    if (state != -1) return state;
    state = 0;
    if (pos == highest_trit - 1) {
        if (carryX == 0) return (state = leq);
        return state;
    }
    int xpos = carry(xvec[pos], carryX);
    int ypos = carry(yvec[pos], carryY);
    pair<int,int> carries = {carryX, carryY};
    for (int add : {0, 1, 2}) {
        carryX = carries.first; carryY = carries.second;
        int addX = add;
        int newxpos = carry(xpos, addX);
        int addY = add;
        int newypos = carry(ypos, addY);
        if (newxpos % 2 != newypos % 2) continue; // not the same parity;
        carryX += addX, carryY += addY;
        state += dfs(pos - 1, carryX, carryY, 
                        (newxpos < xlim[pos] || (newxpos == xlim[pos] && leq)));
    }
    return state;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        reset();
        int x, y, d;
        cin >> d >> x >> y;
        if (x < y) swap(x, y);
        xlim = dec_to_ternary(x + d); ylim = dec_to_ternary(y + d);
        xvec = dec_to_ternary(x); yvec = dec_to_ternary(y);
        for (int i = 0; i < xlim.size(); i++) {
            if (xlim[i]) {
                highest_trit = i;
                break;
            }
        }
        cout << dfs(39, 0, 0, 1) << endl;
    }


    return 0;
}