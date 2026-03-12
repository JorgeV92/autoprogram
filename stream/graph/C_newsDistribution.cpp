#include <iostream>
#include <vector>
#include <numeric>

class dsu {
public:
    dsu(int _n) : n(_n) {
        par.resize(n);
        std::iota(par.begin(), par.end(), 0);
        sz.assign(n, 1);
    }

    int find(int x) {
        if (x == par[x])
            return x;
        return par[x] = find(par[x]);
    } 

    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (sz[x] < sz[y])
            std::swap(x, y);
        sz[x] += sz[y];
        par[y] = x; 
        return true;
    }

    int size(int x) {
        return sz[find(x)];
    }

private:
    std::vector<int> par;
    std::vector<int> sz;
    int n;
};

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    int n, m;
    std::cin >> n >> m;
    dsu d(n);
    for (int i = 0; i < m; i++) {
        int k;
        std::cin >> k;
        if (k == 0)  continue;
        int leader;
        std::cin >> leader;
        leader--;
        for (int j = 1; j < k; j++) {
            int x;
            std::cin >> x;
            x--;
            d.unite(leader, x);
        }
    }

    for (int i = 0; i < n; i++) {
        std::cout << d.size(i) << " ";
    }
    std::cout << "\n";
    return 0;
}