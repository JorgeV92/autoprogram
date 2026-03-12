#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

const int maxn = 100005;

long long c[maxn];
vector<int> g[maxn];

class dsu {
public:
    dsu(int _n, const long long* c) : n(_n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        rnk.resize(n, 1);
        mn.resize(n);
        for (int i =0 ; i < n; i++) mn[i]= c[i];
    }

    int find(int x) {
        if (x == p[x]) 
            return x;
        return p[x] = find(p[x]);
    }

    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if (y == x) return false;
        if (rnk[x] < rnk[y]) swap(x, y);
        p[y] = x;
        rnk[x] += rnk[y];
        mn[x] = min(mn[x], mn[y]);
        n--;
        return true;
    }

    long long get_mn_cost(int x) {
        return mn[find(x)];
    }
    
    int cc() {
        return n;
    }

private:
    vector<int> p, rnk;
    vector<long long> mn;
    int n;
};


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0 ;i < n; i++) {
        cin >> c[i];
    }
    dsu d(n, c);
    for (int i =0 ; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
        d.unite(x, y);
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        if (d.find(i) == i) {
            ans += d.get_mn_cost(i);
        }
    }    
    cout << ans << '\n';
    return 0;
}