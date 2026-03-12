#include <iostream>
#include <vector>

using namespace std;

#define pii pair<int,int>
#define vi vector<int>


struct DSU {
    vi e; int c; int mx; void init(int N) { e = vi(N,-1); c = N; mx = 1; }
    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
    bool ssmeSet(int x, int y) { return get(x) == get(y); }
    int size(int x) { return -e[get(x)]; }
    bool unite(int x, int y) {
        x = get(x); y = get(y);
        if (x == y) return false; 
        if (e[x] > e[y]) swap(x, y);
        e[x] += e[y];
        e[y] = x;
        c--;
        mx = max(mx, size(x));
        return true;
    }
    int getC() {return c;}
    int getMaxSize () { return mx; }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    DSU D;
    D.init(n);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        D.unite(a, b);
        cout << D.getC() << " " << D.getMaxSize() << endl;
    }

    return 0;
}
