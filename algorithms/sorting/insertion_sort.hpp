#include <iostream>
#include <vector>

using namespace std;

#ifndef CP_ALGORITHM_INSERTION_SORT_HPP
#define CP_ALGORITHM_INSERTION_SORT_HPP

namespace cp_algorithms {
namespace sorting {

template<typename T, typename Cmp = less<T>> 
struct InsertionSort {
    int N; vector<T> arr; Cmp cmp = Cmp{};
    void init(int _N, vector<T>& A) {
        N = _N;
        arr = A;
        if (A.empty()) {
            cout << "Array is empty\n";
            exit(1);
        }
        insertion_sort();
    } 

    void insertion_sort() {
        print_array();
        for (int i = 1; i < N; i++) {
            T key = arr[i];
            int j = i-1;
            
            while (j >= 0 && cmp(key, arr[j])) {
                arr[j+1] = arr[j];
                j = j-1;
            }
            arr[j+1] = key;
            print_array();
        }
    }

    void print_array() {
        for (int i = 0; i < N; i++) {
            cout << " | " << arr[i] << " | ";
        }
        cout << endl;
    }
};
}
}
#endif