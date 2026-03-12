#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define pii pair<int,int>

constexpr int INF = 1e9;
vector<int> g[2][106];
int d[106][2];


vector<int> shortestAlternateColoredPath(
    int n, vector<vector<int> >& redEdges,
    vector<vector<int> >& blueEdges) {

        for (int i =0 ; i < n; i++) {
            g[0][i].clear();
            g[1][i].clear();
            d[i][0] = INF;
            d[i][1] = INF;
        }

        for (int i = 0; i < redEdges.size(); i++) {
            int a = redEdges[i][0], b = redEdges[i][1];
            g[0][a].push_back(b);
        }

        for (int i = 0; i < n; i++) {
            int a = blueEdges[i][0], b = blueEdges[i][1];
            g[1][a].push_back(b);
        }

        queue<pii> q;
        q.push({0,0});
        q.push({0, 1});
        d[0][0] = 0;
        d[0][1] = 0;        

        while (!q.empty()) {
            auto [v, color] = q.front();
            q.pop();
            for (int u : g[1-color][v]) {
                if (d[u][1-color] > d[v][color] + 1) {
                    d[u][1-color] = d[v][color] + 1;
                    q.push({u, 1-color});
                }
            }
        }

        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = min(d[i][0], d[i][1]);
            if (ans[i] == INF) ans[i] = -1;
        }

        return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}