#include "insertion_sort.hpp"
#include <iostream>
#include <vector>

using namespace std;
using namespace cp_algorithms::sorting;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> a = {3, 7, 4, 9, 5, 2, 6, 1};
    InsertionSort<int> is;
    is.init(a.size(), a);

    return 0;
}