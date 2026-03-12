#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 2e5 + 5;
int n, q;
long long tree[MAXN*2];

void build() {
    for (int i = n-1; i > 0; i--) {
        tree[i] = tree[i<<1] + tree[i<<1|1];
    } 
}

void modify(int p, int val) {
    for (tree[p+=n] += val; p > 1; p >>= 1) {
        tree[p>>1]= tree[p] + tree[p^1]; 
    }
}

long long query(int l, int r) {
    long long res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) res += tree[l++];
        if (r&1) res += tree[--r];
    }
    return res;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;

    vector<long long> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    tree[n] = arr[0];
    for (int i = 1; i < n; i++) {
        tree[n+i] = arr[i] - arr[i-1];
    }

    build();

    while (q--) {
        int t;
        cin >> t;
        if (t == 1 ){
            int a, b;
            long long u;
            cin >> a >> b >> u;
            modify(a-1, u);
            if (b < n) modify(b, -u);
        } else {
            int k;
            cin >> k;
            cout << query(0, k) << endl;
        }
    }
    

    return 0;
}   