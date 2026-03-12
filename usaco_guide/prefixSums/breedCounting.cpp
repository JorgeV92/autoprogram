#include <iostream>
#include <vector>

using namespace std; 

constexpr int N = 10009;
int H[N], G[N], J[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, Q;
    cin >> n >> Q;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        H[i] = H[i-1];
        G[i] = G[i-1];
        J[i] = J[i-1];

        if (x == 1) {
            H[i]++;
        } else if (x == 2) {
            G[i]++;
        } else {
            J[i]++;
        }
    }

    while (Q--) {
        int a, b;
        cin >> a >> b;
        cout << H[b] - H[a-1] << " ";
        cout << G[b] - G[a-1] << " ";
        cout << J[b] - J[a-1] << " " << endl;
    }

    return 0;
}