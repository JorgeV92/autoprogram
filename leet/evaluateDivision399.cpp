#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <unordered_set>

using namespace std;

unordered_map<string, vector<string,double>> g;

double dfs(string v, string t, unordered_set<string>& vis, double acc) {
    if (v == t) {
        return acc;
    }
    vis.insert(v);
    for (auto& e : g[v]) {
        string u = e.first;
        double w = e.second;
        
        if (vis.find(u) == vis.end()) {
            double res = dfs(u, t, vis, acc * w);
            if (res != -1.0) {
                return res;
            }
        }
    }
    return -1.0;
}

vector<double> calcEquation(vector<vector<string>>& equations, 
                            vector<double>& values, 
                            vector<vector<string>>& queries) {

    for (int i = 0; i < equations.size(); i++) {
        string A = equations[i][0];
        string B = equations[i][1];
        double k = values[i];

        g[A].push_back({B, k});
        g[B].push_back({A, 1.0/k});
    }

    vector<double> res;
    for (auto& q : queries) {
        string a = q[0];
        string b = q[1];

        if (g.find(a) == g.end() || g.find(b) == g.end()) {
            res.push_back(-1.0); 
        } else if (a == b) {
            res.push_back(1.0);
        } else {
            unordered_set<string> vis;
            res.push_back(dfs(a, b, vis, 1.0));
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}