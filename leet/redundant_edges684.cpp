#include <iostream>
#include <vector>

using namespace std;

struct DSU {
    vector<int> e; void init(int N) { e = vector<int>(N, -1); }
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

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU D;
        int n = edges.size();
        D.init(n+1);
        for (const auto& e : edges) {
            if (D.sameSet(e[0], e[1])) {
                return {e[0], e[1]};
            } 
            D.unite(e[0], e[1]);
        }

        return {};
    }
    
};

int main() {
    return 0;
}