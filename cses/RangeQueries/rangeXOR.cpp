#include <iostream>
#include <vector>

using namespace std; 

const int MAXN = 2e5 + 7;
int n, q;
int tree[MAXN*2];

void build() {
    for (int i = n-1; i > 0; i--) {
        tree[i] = tree[i<<1] ^ tree[i<<1|1];
    }
}

int query(int l ,int r) {
    int res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) res ^= tree[l++];
        if (r&1) res ^= tree[--r];
    }
    return res;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> tree[i+n];
    }

    build();

    while (q--) {
        int a, b;
        cin >> a >> b;
        a--;
        cout << query(a, b) << endl;
    }

    return 0;
}