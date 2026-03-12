// 1135. Connecting Cities with Minimum Cost
//
// There are n cities labeled from 1 to n. You are given the integer n and an array connections where 
// connections[i] = [x_i, y_i, cost_i] indicates that the cost of connecting city x_i to y_i (bidirectional) is cost_i.
//
// Return the minimum cost to connect all the n cities such that there is at least one path between each pair of cities. if 
// it is impossible to connect all cities return -1;
//
// The cost is the sum of the connections costs used


#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int INF = 1000000000;

struct Edge {
    int w = INF;
    int to = -1;
    // we need to add a comparator so we can use
    // in set or queues
    bool operator<(Edge const& other) const {
        return make_pair(w, to) < make_pair(other.w, other.to);    
    }
};

class Solution {
private:
    vector<vector<int>> adj;
    vector<vector<Edge>> g;

    int prim_n2() {
        int n = adj.size();
        int total_weight = 0;   
        vector<bool> selected(n, false);
        vector<Edge> min_e(n);
        min_e[1].w = 0;
        
        for (int i = 1; i < n; i++) {
            int v = -1;
            for (int j = 1; j < n; j++) {
                if (!selected[j] && (v == -1 || min_e[j].w < min_e[v].w)) {
                    v = j;
                }
            }

            if (v == -1 || min_e[v].w == INF) return -1;
            
            selected[v] = true;
            total_weight += min_e[v].w;
            for (int to = 1; to < n; to++) {
                if (adj[v][to] < min_e[to].w) {
                    min_e[to] = {adj[v][to], v};
                }
            }
        }

        return total_weight;
        // Solution is to SLOW O(N^2) without using set or priority queue 
    }

    int prim_set() {
        int n = g.size();
        int total_weight = 0;
        vector<Edge> min_e(n);
        min_e[1].w = 0;
        set<Edge> q;
        q.insert({0, 1}); // (weight, node)
    
        vector<bool> selected(n, false);
        for (int i = 1; i < n; i++) {
            if (q.empty()) return -1;
            int v = q.begin()->to;
            selected[v] = true;
            total_weight += q.begin()->w;
            q.erase(q.begin());

            for (Edge e  : g[v]) {
                int to = e.to;
                int len = e.w;
                if (!selected[to] && len < min_e[to].w) {
                    q.erase({min_e[to].w, to});
                    min_e[to] = {len, v};
                    q.insert({len, to});
                }
            }
        }

        return total_weight;
    }

public:

    int minimumCost(int n, vector<vector<int>>& connections) {
        adj.assign(n+1, vector<int>(n+1));
        g = vector<vector<Edge>>(n+1);
        for (const auto& c : connections) {
            int u = c[0];
            int v = c[1];
            int w = c[2];
            adj[u][v] = w;
            adj[v][u] = w;
            g[u].push_back({w, v});
            g[v].push_back({w, u});
        }
        
        int mst_weight = prim_n2();
        return mst_weight;
    }
    
};

int main() {

    return 0;
}

