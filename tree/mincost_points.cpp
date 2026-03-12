#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

struct Edge {
    int w = INF;
    int to = -1;
};

int minCostConnectPoints(vector<vector<int>>& points) {
    int n = points.size();
    vector<vector<int>> adj(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        int x = points[i][0];
        int y = points[i][1];
        for (int j = i+1; j < n; j++) {
            int x2 = points[j][0];
            int y2 = points[j][1];
            int d = abs(x - x2) + abs(y - y2);
            adj[i][j] = d;
            adj[j][i] = d;
        }
    }

    int total_weight = 0;
    vector<bool> selected(n);
    vector<Edge> min_e(n);
    min_e[0].w = 0;

    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++) {
            if (!selected[j] && (v == -1 || min_e[j].w < min_e[v].w)) {
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
    

}


int main() {

    return 0;
}
