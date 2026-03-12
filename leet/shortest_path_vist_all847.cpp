#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9 + 7;

int n;
vector<vector<int>> g;
int cache[12][(1 << 12) + 1];

int dp(int node, int mask) {
    if (cache[node][mask] != 0) {
        return cache[node][mask];
    }
    if ((mask & (mask - 1)) == 0) {
        return 0;
    }

    cache[node][mask] = INF;
    for (int v : g[node]) {
        if ((mask & (1 << v)) != 0) {
            int vistedNode = dp(v, mask);
            int notVisitedNode = dp(v, (mask ^ (1 << node)));
            int bestOption = min(vistedNode, notVisitedNode);
            cache[node][mask] = min(cache[node][mask], 1 + bestOption);
        }
    } 

    return cache[node][mask];
}

int shortestPathLength(vector<vector<int>>& graph) {
    g = graph;
    n = graph.size();
    int endMask = (1 << n) - 1;

    int best = INF;
    for (int node = 0; node < n; node++) {
        best = min(best, dp(node, endMask));
    }
    return best;
}

int main() {
    return 0;
}