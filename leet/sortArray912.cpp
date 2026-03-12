#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;


struct MergeSort {
    int n{};
    void init(vector<int>& arr) {
        n = arr.size();
        mergesort(0, n-1, arr);
    }
    void mergesort(int l, int r, vector<int>& arr) {
        if (l >= r) {
            return;
        }
        int m = l + (r-l) / 2;
        mergesort(l, m, arr);
        mergesort(m+1, r, arr);
        merge(l, m, r, arr);
    }

    void merge(int l, int m, int r, vector<int>& arr) {
        int i = l, j = m + 1;
        vector<int> tmp;
        while (i <= m && j <= r) {
            if (arr[i] <= arr[j]) {
                tmp.push_back(arr[i++]);
            } else {
                tmp.push_back(arr[j++]);
            }
        }

        while (i <= m) tmp.push_back(arr[i++]);
        while (j <= r) tmp.push_back(arr[j++]);
        for (int i = l; i <= r; i++) {
            arr[i] = tmp[i-l];
        }
    }
};

struct QuickSort1 {
    int n;
    void init(vector<int>& arr) {
        n = arr.size();
        quicksort(0, n-1, arr);
    }

    void quicksort(int lo, int hi, vector<int>& arr) {
        if (lo >= hi) return;
        int m = lo + (hi-lo) / 2;
        int pivot = arr[m];
        int j = partition(lo, hi, pivot, arr);
        quicksort(lo, j-1, arr);
        quicksort(j, hi, arr);
    }

    int partition(int lo, int hi, int pivot, vector<int>& arr) {
        while (lo <= hi) {
            while (arr[lo] < pivot) lo++;
            while (arr[hi] > pivot) hi--;
            if (lo <= hi) {
                swap(arr[lo], arr[hi]);
                lo++; hi--;
            }
        }
        return lo;
    }
};



struct QuickSort2 {
    int n;
    void init(vector<int>& arr) {
        n = arr.size();
        auto rng = std::default_random_engine{};
        ranges::shuffle(arr, rng);
        quicksort(0, n-1, arr);
    }

    void quicksort(int l, int r, vector<int>& arr) {
        if (r <= l) return;
        int j = partition(l, r, arr);
        quicksort(l, j-1, arr);
        quicksort(j+1, r, arr);
    }

    int partition(int l, int r, vector<int>& arr) {
        int i = l, j = r+1;
        int v = arr[l];
        while (true) {
            while (arr[++i] < v) if (i == r) break;
            while (arr[--j] > v) if (j == l) break;
            if(i >= j) break;
            swap(arr[i], arr[j]) ;
        }
        swap(arr[l], arr[j]);
        return j;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> a{5, 2, 55, 3, 10, 6};

    // MergeSort ms;
    // ms.init(a);

    QuickSort qs;
    qs.init(a);

    for (int x : a) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}