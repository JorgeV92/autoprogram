#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

#define vi vector<int>
#define ll long long

struct edge {
    int from;
    int to;
    int cost;
};

struct DSU {
    vi e; void init(int N) { e = vi(N, -1); }
    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
    bool sameSet(int x, int y) { return get(x) == get(y); }
    int size(int x) { return -e[get(x)]; }
    bool unite(int x, int y) {
        x = get(x); y = get(y);
        if (x == y) return false;
        if (e[x] > e[y]) swap(x, y); 
        e[x] += e[y];
        e[y] = x;
        return true;
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<edge> edges;
    vector<int> teams(n);
    for (int i = 0; i < n; i++) {
        cin >> teams[i];
    }
    for (int i = 0; i < n; i++) {
        int u = teams[i];
        for (int j = i + 1; j < n; j++) {
            int v = teams[j];
            edges.push_back({i, j, (u ^ v)});
        }
    }

    sort(edges.begin(), edges.end(), [&edges](const auto& a, const auto& b) {
        return a.cost > b.cost;
    });

    DSU D;
    D.init(n);
    int total_points = 0;
    int added = 0;
    for (const auto& e : edges) {
        if (D.unite(e.from, e.to)) {
            total_points += e.cost;
            added++;
            if (added == n-1) {
                cout << total_points << endl;
                return 0;
            }
        }
    }

    return 0;
}