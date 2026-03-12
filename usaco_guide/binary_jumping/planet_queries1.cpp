#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 2e5 + 5;
const int MAX_D = 30;

int N, Q;
int pr[MAX_N][MAX_D];

int go_up(int x, int up) {
    for (int j = MAX_D-1; j >= 0; j--) {
        if (up & (1 << j)) {
            x = pr[x][j];
        }
    }
    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    for (int i = 1; i <= N; i++) {
        cin >> pr[i][0];
    }

    for (int j = 1; j < MAX_D; j++) {
        for (int i = 1; i <= N; i++) {
            pr[i][j] = pr[pr[i][j-1]][j-1];
        }
    }

    while (Q--) {
        int a, k;
        cin >> a >> k;
        cout << go_up(a, k) << endl;
    }


    return 0;
}