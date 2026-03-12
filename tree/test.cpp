#include <iostream>
#include <vector>

using namespace std;

int MAX_N = 2000;
int INF = 1e9;
vector<vector<int>> adj;

struct Edge {
    int w = INF;
    int to = -1;
};


int prim() {
    // O(n^2)
    vector<vecotr<int>> points{{1,1}, {4, 5}};

    adj = vector<vector<int>>(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        int x = points[i][0];
        int y = points[i][1];

        for (int j = i + 1; j < n; j++) {
            int x2 = points[j][0];
            int y2 = points[j][1];

            int d = distance(x, y, x2, y2); // TODO
            adj[i][j] = d;
            adj[j][i] = d;
        }
    }   
        
    int total_weight = 0;
    vector<int> selected(MAX_N);
    vector<Edge> min_e(MAX_N);
    min_e[0].w = 0;
    
    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; i++) {
            if (!selected[j] && (v == -1 || max_e[j].w < max_e[v].w)) {
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


