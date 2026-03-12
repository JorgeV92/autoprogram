#include <iostream>
#include <vector>

using namespace std;


// Prims algorithm 
// If we have a graph G with n vertices and m edges and we want to find 
// a spanning tree of this graph which connects all vertices and has the least 
// weight which is called the minimum spanning tree.
// The MST will contain n - 1 edges.
// For example there are n cities for each pair of cities we are given the cost
// to build a road between them. We have to build roads, such that we can get 
// from each city to every other city and the cost for building all roads is minimal.

// Algorithm 
// The MST is a greedy algorithm where we add one edge at a time. Start with an arbitrary vertex
// as the starting position. Then the minimum cost edge from the source vertex to another vertex is 
// added to the minimum spanning tree. 
// Now we have two vertices. Now we add anthoer minimum edge that has one end in an already selected vertex. 
// (a vertex that is already part of the MST and the other end is a unselected vertex)
//  This process is repeated until the spanning tree contains all vertices or we have n-1 edges which is the same.


// Euclidean Minimum Spanning Tree problem:
// we have n points on a plane and the distance between each pair of points 
// is the Euclidean distance between them using Prims in O(n^2)


int n; 
vector<vector<int>> adj;
const int INF = 1e9;  

struct Edge {
    int w = INF;
    int to = -1;
};

void prim(){
    int total_weight = 0;
    vector<bool> selected(n, false);
    vector<Edge> min_e(n);
    min_e[0].w = 0;
    
    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++ ) {
            if (!selected[j] && (v == - 1 || min_e[j].w < min_e[v].w)) {
                v = j;
            }
        }

        if (min_e[v].w == INF) {
            cout << "No MST" << endl;
        } 

        selected[v] = true;
        total_weight += min_e[v].w;
        if (min_e[v].to != -1) 
            cout << v << " " << min_e[v].to << endl;

        for (int to = 0; to < n; to++) {
            if (adj[v][to] < min_e[to].w) 
                min_e[to] = {adj[v][to], v};
        } 
    }
}

int main() {

    return 0;
}
