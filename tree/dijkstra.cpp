#include <iostream>
#include <vector>

using namespace std;


// Dijkstra Algorithm 
// 
// Given a directed or undirected weighted graph with n vertices and m edges. 
// The weight of all edges are non-negative. You are also given the start 
// start vertex s. Your task is to find the shortest paths form a starting
// vertex s to all other vertices and output the shortest paths.

// Algorithm 
//
// Create an array d[] where each vertex v we store the current length of the 
// shortest path from s -> v. Initially d[s] = 0, and all other v in V the
// length is infinity. 
//              
//                      d[v] = infinity, v != s
//
// We also maintain a boolean array u[] which stores for each vertex v wether its marked 
// 
//                              u[v] = false
//
// Dijkstra's algorithm runs for n iterartions. 
// At each step a vertex v is chosen as unmarked vertex which has the minimum d[v]
// The first iteration s will chosen since it has the mininum d[s]
// We mark the selected vertex. Next, from vertex v relaxations are performed:  all 
// edges of the form (v, to) are considered, and for each vertex to in V the algorithm 
// tries to improve the value d[to]. If the length of the current edge equals len, 
// the code for relaxations is the following: 
//
//                  d[to] = min(dp[to], dp[v) + len)
//
// Note that if some vertices are unreachable starting from vertex s, the values of 
// d[v] will all containn infinity.

// Restoring Shortest Paths
//
// We will maintain an array of predecessors p[] in which for each vertex v != s, 
// p[v] is the penultimate vertex in the shortest path form s -> v. 
// Starting with v, repeatedly take the predecessor of the current vertex 
// until we reach the starting vertex s to get the shortest path vertives listed
// in reverse order. Then the shortest path P to the vertex v is equal to:
//
//                      P = (s, ...., p[p[p[v]]], p[[p[v]]], p[v], v)
//
// For each successful relaxation, i.e., when for some selected vertex v, there is an 
// improvement in the distance to some vertex to, we update the predecessor vertex 
// 
//                              p[to] = v
//
// 

const int INF =  1e9;
vector<vector<pair<int,int>>> adj;

void dijkstra(int s, vector<int>& d, vector<int>& p) {
    int n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);
    vector<bool> u(n ,false);

    d[s] = 0;
    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++) {
            if (!u[j] && (v == -1 || d[j] < d[v] )) {
                v = j;
            }
        }

        if (d[v] = INF) break;
        u[v] = true;
        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;
            
            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
            }
        }
    }
}

vector<int> restore_path(int s, int t, vector<int> const& p) {
    vector<int> path;
    
    for (int v = t; v != s; v = p[v]) {
        path.push_back(v);
    }
    path.push_back(s);
    
    reverse(path.begin(), path.end());
    return path;
}


int main() {

    return 0;
}
