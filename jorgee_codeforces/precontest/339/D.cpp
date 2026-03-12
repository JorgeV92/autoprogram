#include <iostream>
#include <vector>
#include <cmath>

using namespace std; 

constexpr int MAXN = 2e5;
int t[MAXN*2];
int n, q;


void build(int node, int tl, int tr, int h) {
    if (tl == tr) {
        return;
    }
    int mid = (tl + tr) >> 1;
    build(node<<1, tl, mid, h-1);
    build(node<<1|1, mid+1, tr, h-1);
    if ((h&1)) {
        t[node] = t[node<<1] | t[node<<1|1];
    } else {
        t[node] = t[node<<1] ^ t[node<<1|1];
    }
}   

void modify(int p, int val ){
    int i = 1;
    for (t[p+=n] = val; p > 0; p >>= 1 ) {
        if ((i&1))
            t[p>>1] = t[p] | t[p^1];
        else 
            t[p>>1] = t[p] ^ t[p^1];
        i++;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    n = (1 << n);
    for (int i = 0; i < n; i++) {
        cin >> t[i+n];
    }

    build(1, 0, n-1, log2(n));

    while (q--) {
        int p, b;
        cin >> p >> b;
    
        modify(p-1, b);
        cout << t[1] << endl;
    }
    return 0;
}