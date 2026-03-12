#include <iostream>
#include <vector>

using namespace std; 

constexpr int N = 100009;
using ll = long long;

ll H[N], P[N], S[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        char x;
        cin >> x;

        H[i] = H[i-1];
        P[i] = P[i-1];
        S[i] = S[i-1];

        if (x == 'H') {
            H[i]++;
        } else if (x == 'P') {
            P[i]++;
        } else {
            S[i]++;
        }
    }

    int mx = 0;
    for (int i =1 ; i <=n ;i++) {
        int prev = max({H[i], P[i], S[i]});
        int nxt = max(
            {H[n]-H[i], P[n]-P[i], S[n]-S[i]}
        );
        mx = max(mx, prev + nxt);
    }

    cout << mx << endl;
    return 0;
}