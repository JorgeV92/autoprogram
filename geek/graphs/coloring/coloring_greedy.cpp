#include <iostream>
#include <vector>

using namespace std;

class Graph {
public:
    Graph(int v) : V{v}, adj{v} {}
    void addEdge(int v, int w);
    void greedyColoring();

private:
    int V;
    vector<vector<int>> adj;
};

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void Graph::greedyColoring() {
    int res[V];
    res[0] = 0;
    
    for (int u = 1; u < V; u++) 
        res[u] = -1;

    bool available[V];
    for (int cr = 0; cr < V; cr++)
        available[cr] = false;
    
    for (int u = 1; u < V; u++) {
        for (auto& v : adj[u]) {
            if (res[v] != -1) 
                available[res[v]] = true;
        }
        
        int cr;
        for (cr = 0; cr < V; cr++) {
            if (available[cr] == false)
                break;
        }
        res[u] = cr;

        for (auto& v : adj[u]) {
            if (res[v] != -1) 
                available[res[v]] = false;
        }
    }

    for (int u = 0; u < V; u++) 
        cout << "Vertex " << u << " ----> Color "
             << res[u] << endl;
}