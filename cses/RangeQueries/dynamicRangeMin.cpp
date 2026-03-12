#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

const int MAXN = 2e5 + 5;
int tree[MAXN*2];
int n;

void build() {
    for (int i = n -1; i > 0; i--) {
        tree[i] = min(tree[i<<1], tree[i<<1|1]);
    }
}

void modify(int p, int val) {
    for (tree[p+=n] = val; p > 1; p >>= 1) {
        tree[p>>1] = min(tree[p], tree[p^1]);
    }
}

int query(int l, int r) {
    int res = 2e9;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) res = min(res, tree[l++]);
        if (r&1) res = min(res, tree[--r]);
    }
    return res;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> n >> q;

    for (int i = 0; i < n; i++) {
        cin >> tree[n+i];
    }
    build();

    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int k, u;
            cin >> k >> u;
            k--;
            modify(k, u);
        } else {
            int a, b;
            cin >> a >> b;
            a--; 
            cout << query(a, b) << endl;
        }
    }
    return 0;
}