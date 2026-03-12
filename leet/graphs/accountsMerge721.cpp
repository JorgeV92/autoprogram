#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std; 


class DFS {
public:
    unordered_map<string, vector<string>> adj;
    unordered_set<string> vis;

    void dfs(string& email, vector<string>& path) {
        vis.insert(email);
        path.push_back(email);
        for (auto nxt : adj[email]) {
            if (vis.find(nxt) == vis.end()) {
                dfs(nxt, path);
            }
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        for (auto a : accounts) {
            string f = a[1];
            int sz = a.size();
            for (int i = 2; i < sz; i++) {
                string email = a[i];
                adj[f].push_back(email);
                adj[email].push_back(f);
            }
        }

        vector<vector<string>> out;
        for (auto a : accounts) {
            string name = a[0];
            string f = a[1];
            if (vis.find(f) == vis.end()) {
                vector<string> path;
                path.push_back(name);
                dfs(f, path);
                sort(path.begin() + 1, path.end());
                out.push_back(path);
            }
            
        }
        return out;
    }   
};

class UnionFind {
public:

    struct DSU {
        vector<int> e; void init(int N) { e = vector<int>(N,-1); }
        int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
        bool unite(int x, int y) {
            x = get(x), y = get(y);
            if (x == y) return false;
            if (e[x] > e[y]) swap(x, y);
            e[x] += e[y];
            e[y] = x;
            return true;
        }       
    };

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n= accounts.size();
        DSU D;
        D.init(n);
        unordered_map<string, int> emailGroup;
        for (int i = 0; i < n; i++) {
            int sz = accounts[i].size();
            for (int j = 1; j < sz; j++) {
                string f = accounts[i][j];
                if (emailGroup.find(f) == emailGroup.end()) {
                    emailGroup[f] = i;
                } else {
                    D.unite(i, emailGroup[f]);
                }
            }
        }

        unordered_map<int, vector<string>> comp;
        for (const auto& [email, group] : emailGroup) {
            comp[D.get(group)].push_back(email);
        }

        vector<vector<string>> out;
        for (const auto& [group, emails] : comp) {
            string name = accounts[group][0];
            vector<string> cp{name};
            cp.insert(cp.end(), emails.begin(), emails.end());
            sort(cp.begin() + 1,cp.end());
            out.push_back(cp);
        }
        return out;
    }
};



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}