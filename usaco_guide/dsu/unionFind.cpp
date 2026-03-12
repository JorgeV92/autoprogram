#include <iostream>
#include <vector>

using namespace std;

struct DSU {
    vector<int> e;
    void init(int N) {
        e = vector<int>(N, -1);
    }
    int get(int x) {
        return e[x] < 0 ? x : e[x] = get(e[x]);
    }
    bool sameSet(int a, int b) { return get(a) == get(b); }
    int size(int x)  {return -e[get(x)]; }
    bool unite(int x, int y) {
        x = get(x);
        y = get(y);
        if (x == y) return false;
        if (e[x] > e[y]) swap(x, y);
        e[x] += e[y];
        e[y] = x;
        return true;
    }
};

int main() {    

    int N, Q;
    cin >> N >> Q;

    DSU D;
    D.init(N);

    for (int q = 0 ; q < Q; q++) {
        int t, u, v;
        cin >> t >> u >> v;
        if (!t) {
            D.unite(u, v);    
        } else {
            if (D.sameSet(u, v)) {
                cout << 1 << endl;
            } else {
                cout << 0 <<  endl;
            }

        }

    }

    
    return 0;
}
