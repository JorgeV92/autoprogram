#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
    Articulation Points

    We say that a vertex V in a graph G with C connected components is an 
    articulation point if its removal increases the number of connected comonents
    of G.
*/

// Naive approach O(V * (V + E))
/*

    for every vertex V in the graph G do
        Remove V from G
        if the number of connected components increases then V is an articulation point
        Add V back to G
*/

// Tarjan's approach O(V + E)


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}