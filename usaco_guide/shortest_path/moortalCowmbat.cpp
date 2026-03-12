#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORE(i,a,b) for (int i = (a); i <= (b); i++)
const int N = 100005;
int n, m, K;
string s;

int dist[26][26];
int cost[N][26];
int prefix[N][26];
int dp[N][26];
int mini[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> K >> s;

    FOR(i, 0, m) {
        FOR(j,0,m) {
            cin >> dist[i][j];
        }
    } 

    FOR(k, 0, m) {
        FOR(i,0,m) {
            FOR(j,0,m) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    
    FORE(i,1,n) {
        FOR(j,0,m) {
            cost[i][j] = dist[s[i-1]-'a'][j];
            prefix[i][j] = prefix[i-1][j] + cost[i][j];
        }
    }

    memset(dp, 0x3f, sizeof(dp));
    memset(mini, 0x3f, sizeof(mini));
    mini[0] = 0;

    FORE(i,1,n) {
        FOR(j,0,m) {
            dp[i][j] = min(dp[i][j], dp[i-1][j] + cost[i][j]);
            if (i >= K) {
                dp[i][j] = min(dp[i][j], prefix[i][j] - prefix[i-K][j] + mini[i-K]);
                mini[i] = min(mini[i], dp[i][j]);
            }
        }
    }

    cout << mini[n] << endl;
    return 0;
}