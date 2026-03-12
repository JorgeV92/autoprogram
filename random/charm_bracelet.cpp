#include <iostream>
#include <vector>

using namespace std;

const int MAXM = 1300;

int dp[MAXM];

struct charm {
    int w;
    int d;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<charm> charms(N);

    for (int i = 0; i < N; i++) {
        int w, d;
        cin >> w >> d;
        charms[i] = {w, d};
    }

    for (int i = 0; i < N; i++) {
        for (int j = M; j >= charms[i].w; j--) {
            dp[j] = max(dp[j], dp[j - charms[i].w] + charms[i].d);
        }
    }

    cout << dp[M] << endl;

    return 0;
}