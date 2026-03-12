#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdlib>

using namespace std;

#ifndef CP_ALGORITHMS_ALGORITHMS_SORTING_QUICKSORT_HPP
#define CP_ALGORITHMS_ALGORITHMS_SORTING_QUICKSORT_HPP


namespace cp_algorithms {
namespace sorting {

template<typename T, typename Cmp = less<T>>
struct QuickSort {
    int N; vector<T> arr; Cmp cmp = Cmp{}; 
    void init(int _N, vector<T>& a) {
        N = _N;
        if (a.empty()) {
            cout << "The array is empty\n";
            exit(1);
        }
        arr = vector<T>(a.begin(), a.end());
        quicksort(0, N-1);
    }

    int partition(int l,  int r, T pivot) {
        while (l <= r) {
            while (cmp(arr[l], pivot)) l++; // arr[l] < pivot
            while (cmp(pivot, arr[r])) r--; // arr[r] > pivot
            if (l <= r) {
                swap(arr[l], arr[r]);
                l++; r--;
            }
        }
        return l;
    }

    void quicksort(int l, int r) {
        if (l >= r) {
            return;
        }
        int m = (l + (r-l) / 2);
        T pivot = arr[m];
        int partition_index = partition(l, r, pivot);
        quicksort(l, partition_index-1);
        quicksort(partition_index, r);
    }
};

} 
} 

#endif // CP_ALGORITHMS_ALGORITHMS_SORTING_QUICKSORT_HPP


