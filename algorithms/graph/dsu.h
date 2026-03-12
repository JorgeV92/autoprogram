#include <numeric>
/**
 * Description: Disjoint Set Union with path compression
 	* and union by size. Add edges and test connectivity. 
 	* Use for Kruskal's or Boruvka's minimum spanning tree.
 * Time: O(\alpha(N))
 */
#include <vector>

using namespace std;

using vi = vector<int>;

struct DSU {
    vi e; void init(int N) { e = vi(N,-1); }
    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
    int size(int x) { return -e[get(x)]; }
    bool sameSet(int x, int y) { return get(x) == get(y); }
    bool unite(int x, int y) {
        x = get(x); y = get(y); if (x == y) return false;
        if (e[x] > e[y]) swap(x, y);
        e[x] += e[y]; e[y] = x;
        return true;
    }
};

/**tcT> T kruskal(int N, vector<pair<T,pi>> ed) {
	sort(all(ed));
	T ans = 0; DSU D; D.init(N); // edges that unite are in MST
	each(a,ed) if (D.unite(a.s.f,a.s.s)) ans += a.f; 
	return ans;
}*/

class dsu {
public:
    vector<int> p, sz;
    int n;
    
    dsu(int N) {
        p.resize(N);
        sz.assign(N, 1);
        iota(p.begin(), p.end(), 0);
    }
    
    int get(int x) {
        return (x == p[x] ? x : (p[x] = get(p[x])) );
    }
    
    bool unite(int x, int y) {
        x = get(x), y = get(y);
        if (x == y) return false;
        if (sz[x] < sz[y]) swap(x, y);
        sz[x] += sz[y];
        p[y] = x;
        return true;
    }
 };

 /*
    This is MountainArray's API interface.
    You should not implement it, 

    class MountainArray:
        def get(self, index: int) -> int:
        def length(self) -> int:

    your function find_in_array(target, mountain_array) given the target and the mountain array 
    look for the target in the mountain array with minimum calls to the api 
    and return leftmost index where this occurs, or -1 if it doesnt exist 
    length >= 3 


    Sandra:
        773-735-0348
        rush more
    
 */