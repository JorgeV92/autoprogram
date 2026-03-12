#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> g;
vector<vector<int>> all_paths;
vector<int> path;
int N;

void dfs(int v, vector<int>& path) {
    path.push_back(v);
    if (v == N-1) {
        all_paths.push_back(path);
    } else {
        for (int u : g[u]) {
            dfs(u, path);
        }
    }
    path.pop_back();
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    g = graph;
    N = graph.size();
    dfs(0, path);
    return all_paths;
}

int main() {

    return 0;
}
