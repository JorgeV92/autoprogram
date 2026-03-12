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

vector<string> grid;
vector<vector<bool>> vis;
vector<vector<int>> dp;
int N, M;
int dx[8]{-1,-1-1,0,0,1,1,1};
int dy[9]{-1,0,1,-1,1,-1,0,1};
int global_longest;

bool valid(int r,  int c) {
    return (0 <= r && r < N && 0 <= c && c < M);
}

int dfs(int r, int c) {
    if (dp[r][c] != -1) 
        return dp[r][c];
    int max_path = 1;
    FOR(k,0,8) {
        int nr = r + dx[k];
        int nc = c + dy[k];
        if (valid(nr,nc) && grid[nr][nc] == grid[r][c] + 1) {
            chmax(max_path, 1 + dfs(nr,nc));
        }
    }
    return dp[r][c] = max_path;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (cin >> N >> M && (N !=0 || M !=0 )) {
        grid = vector<string>(N);
        dp = vector<vector<int>>(N, vector<int>(M,-1));

        FOR(i,0,N) {
            cin >> grid[i];
        }
        global_longest = 0;
        FOR(i,0,N) {
            FOR(j,0,M) {
                if (grid[i][j] == 'A') {
                    chmax(global_longest, dfs(i,j));
                }
            }
        }
        cout << "Case " << t++ << ": " << global_longest << '\n';
    }


    return 0;
}