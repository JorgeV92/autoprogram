#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>

using namespace std;

/*
    How to remove duplicates in a vector
*/
void remove_duplicate() {
    vector<int> A(100);
    iota(A.begin(), A.end(), 0);
    for (int i = 10; i <= 20; i += 2) {
        A[i] = 3;
    }
    vector<int> B(A.begin(), A.end());
    // Using a vector, sort + unique 
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());

    // Conver to a set manually
    // Faster than the unique method 
    set<int> s;
    unsigned size = B.size();
    for (unsigned i = 0; i < size; i++) {
        s.insert(B[i]);
    }
    B.assign(s.begin(), s.end());

    
}


int main() {
    return 0;
}
