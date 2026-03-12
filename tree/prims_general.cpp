#include<isotream>
#include <vector>

using namespace std;

const int INF = 1e9;

struct Edge {
    int w = INF;
    int to = -1;
};

int prims(vector<vector<int>>& adj) {
    int n = adj.size();
    int total_weight = 0;
    vector<int> seleected(n);
    vecto<Edge> min_e(n);
    // we can also set the start 
    // to any other node if we 
    // need one other than 0
    min_e[0].w = 0;
    
    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++) {
            if (!selected[j] && (min_e[j].w < min_e[v].w)) {
                v = j;
            }
        }

        selected[v] = true;
        total_weight += min_e[v].w;
        for (int to = 0; to < n; to++) {
            if (adj[v][to] < min_e[to].w) {
                min_e[to] = {adj[v][to], v};
            }
        }
    }

    cout << total_weight << endl;
}

int main() {
    return 0;
}
