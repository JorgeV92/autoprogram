#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

/*
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
    }
};

*/

vector<vector<pair<int,double>>> adj;

double dfs(int v, int t, double total, vector<bool>& vis) {
    if (v == t) {
        return total;
    }
    vis[v] = true;
    for (const auto& [u, w] : adj[v]) {
        if (!vis[u]) {
            double res = dfs(u, t, total* w, vis);
            if (res != -1.0) return res;
        }
    }
    return -1.0;
}

vector<double> calcEquation(vector<vector<string>>& equations, 
                            vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, int> id;
        int idx = 0;
        for (const auto& qs : equations) {
            string a = qs[0], b = qs[1];
            if (!id.count(a)) id[a] = idx++;
            if (!id.count(b)) id[b] = idx++;
        }

        adj = vector<vector<pair<int, double>>>(idx);
        for (int i =0; i < (int)equations.size(); i++) {
            string a  = equations[i][0], b = equations[i][1];
            adj[id[a]].push_back({id[b], values[i]});
            adj[id[b]].push_back({id[a], 1.0 / values[i]});
        }

        vector<double> ans;
        for (const auto& qs: queries) {
            string a = qs[0], b = qs[1];
            if (!id.count(a) || !id.count(b)) {
                ans.push_back(-1.0);
                continue;
            }

            int u = id[a];
            int v = id[b];

            if (u == v) {
                ans.push_back(1.0);
                continue;
            }
            
            vector<bool> vis(idx,false);
            ans.push_back(dfs(u, v, 1.0, vis));
        }

        return ans;
}



int main() {

    return 0;
}