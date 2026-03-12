#include "quicksort.hpp"
#include <iostream>
#include <vector>
#include <string>

using namespace std;
using namespace cp_algorithms::sorting;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> a = {50, 23, 9, 10, 2};
    QuickSort<int> qs;
    qs.init(5, a);
    
    for (int x : qs.arr) {
        cout << x << " ";
    }
    cout << endl;


    vector<string> strs = {"Tourist", "Demon", "Levi", "Alan"};
    QuickSort<string> qs_stirngs;
    qs_stirngs.init(4, strs);

    for (string s : qs_stirngs.arr) {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}