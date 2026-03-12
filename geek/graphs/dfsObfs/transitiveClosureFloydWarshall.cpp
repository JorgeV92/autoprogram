#include <iostream>
#include <vector>

using namespace std; 

constexpr int inf = 1e9;

vector<vector<int>> transitiveClosure(int N, vector<vector<int>> graph) {
    vector<vector<int>> dist(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    for (int i = 0; i < N; i++) 
        dist[i][i] = 1;

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (dist[i][k] && dist[k][j]) 
                    dist[i][j] = 1;
            }
        }
    }
    return dist;
}

// with real value distances 
vector<vector<int>> floydWarshall(const vector<vector<int>> &graph) {
    vector<vector<int>> dist = graph;
    int V = dist.size();
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != inf && dist[k][j] != inf) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}