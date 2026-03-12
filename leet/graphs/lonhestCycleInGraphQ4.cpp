#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<int> g[100006];
    int color[100006];  
    int height[100006];
    int cycle;

    void dfs(int v, int depth) {
        color[v] = 1;
        height[v] = depth;

        for (int u : g[v]) {
            if (color[u] == 0) {
                dfs(u, depth + 1);
            } else if (color[u] == 1) {
                cycle = max(cycle, depth - height[u] + 1);
            }
        }

        color[v] = 2;
    }

public:
    int longestCycle(vector<int>& edges) {
        int n = (int)edges.size();
        cycle = 0;

        for (int i = 0; i < n; i++) {
            color[i] = 0;
            height[i] = 0;
            g[i].clear();
        }

        for (int i = 0; i < n; i++) {
            if (edges[i] != -1) g[i].push_back(edges[i]);
        }

        for (int i = 0; i < n; i++) {
            if (color[i] == 0) dfs(i, 1);
        }

        return cycle == 0 ? -1 : cycle;
    }
};

class ASolution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<bool> vis(n);
        int ans = -1;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                vector<int> cycle;
                int j = i;
                for (; j != -1 && !vis[j]; j = edges[j]) {
                    vis[j] = true;
                    cycle.push_back(j);
                }
                if (j == -1) {
                    continue;
                }
                for (int k = 0; k < (int)cycle.size(); k++) {
                    if (cycle[k] == j) {
                        ans = max(ans, (int)cycle.size() - k);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};