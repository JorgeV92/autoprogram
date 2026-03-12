#include <iostream>
#include <vector>

using namespace std;

// Distance queries CSES
// dist(A, LCA) = depth[A] - depth[LCA]
// we need a methdo to compute the lowest common ancestor in
// an efficeint way

const int MAX_N = 200001;
const int LOG = 20;
pair<int,int> up[MAX_N][LOG]; // up[v][j] is the 2^j-th ancestor of v stores with edge weight
int depth[MAX_N];
vector<int> edges[MAX_N];

// preprocess and compute LCA and Dist of every node
void dfs(int u, int parent) {
    // do the preprocessing step
    for (int v : edges[u]) {
        if (v == parent) continue;
        depth[v] = depth[u] + edge_len;
        up[v][0] = make_pair(a, edge_len);
        for (int j = 1; j < LOG; j++) {
            int x = up[v][j-1].first;
            up[v][j] = make_pair(
                            up[x][j-1].first, 
                            min(up[v][j-1].second, up[x][j-1].second)
                        );
        }
        dfs(v, u);
    }
}


int get_distance(int a, int b) { // O(LogN)
    if (depth[a] < depth[b]) {
        swap(a, b);
    }
    int distance = 0;
    int k = depth[a] - depth[b];
    for (int j = LOG-1; j >= 0; j--) {
        if (k & (1 << j)) {
            distance += (1 << j);  // 2**j 
            a = up[a][j];
        }
    }

    if (a == b) return distance;
        
    for (int j = LOG-1; j >= 0; j--) {
        if (up[a][j] != up[b][j]) {
            a = up[a][j];
            b = up[b][j];
            distance += 2 * (1 << j);
        }
    }

    return distance + 2;
}

int main() {
    int n, q;
    scanf("%d%d", &n , &q);

    for (int i = 1; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    dfs(1, -1);

    while (q--) {
        int u, v;
        scanf("%d%d", &u, &v);
        int ans = get_distance(u, v);
        printf("%d\n", ans);
    }

    return 0;
} i
