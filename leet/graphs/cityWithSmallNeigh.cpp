#include <iostream>
#include <vector>

using namespace std;

int dist[105][105];
constexpr int inf = 1e9;

int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                dist[i][i] = 0;
            } else {
                dist[i][j] = inf;
            }
        }
    }

    for (const auto& e : edges) {
        int a = e[0];
        int b = e[1];
        int w = e[2];
        dist[a][b] = w;
        dist[b][a] = w;
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int city = -1;
    int total = 0;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (dist[i][j] <= distanceThreshold) {
                cnt++;
            }
        }

        if (cnt <= total) {
            total = cnt;
            city = i;
        }
    }

    return city;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}