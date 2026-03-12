#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
const int max_num_digits = 100;

// dp[x][y][z] - number of ways to complete the number from position x onward, 
// given we’ve already placed y copies of d, and the tightness flag is z. 
int dp[max_num_digits][max_num_digits][2];
int n, m, k, d;

void reset() {
    memset(dp, -1, sizeof(dp));
}

int dfs(int c, int x=0, int y=0, int z=0) { //range [0, c] with state [x][y][z]
    if (dp[x][y][z] != -1) {
        return dp[x][y][z];
    }

    dp[x][y][z] = (y == k);
    if (x == to_string(c).length()) {
        return dp[x][y][z];
    }

    int limit = 9;
    if (!z) { // if the number being formed CAN exceed c
        limit = to_string(c)[x] - '0'; // the xth digit of c
    }

    dp[x][y][z] = 0;
    for (int xth_digit = 0; xth_digit <= limit; xth_digit++) {
        if (z) {
            dp[x][y][z] += dfs(c, x + 1, y + (xth_digit == d), 1);
        } else {
            dp[x][y][z] += dfs(c, x+1, y + (xth_digit == d), xth_digit< limit); 
        }
    }
    return dp[x][y][z];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    reset();
    cin >> n >> m >> k >> d;
    int total = dfs(m);
    reset();
    cout << total - dfs(n-1) << endl;

    return 0;
}