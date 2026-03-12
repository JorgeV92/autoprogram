#include <vector>

#ifndef ALGORITHMS_MERGESORT_H_
#define ALGORITHMS_MERGESORT_H_

class MergeSort {
public:
    MergeSort(std::vector<int>& a) {
        n = a.size();
        arr = a;
        mergesort(0, n-1, arr); 
    }

    void mergesort(int l, int r, std::vector<int>& a) {
        if (l >= r) return;
        int m = l + (r - l) / 2;
        mergesort(l, m, a);
        mergesort(m+1, r, a);
        merge(l, m, r, a);
    }

    void merge(int l, int m, int r, std::vector<int>& a) {
        std::vector<int> tmp;
        int i = l, j = m + 1;
        while (i <= m && j <= r) {
            if (a[i] <= a[j]) {
                tmp.push_back(a[i++]);
            } else {
                tmp.push_back(a[j++]);
            }
        }
    }

private:
    int n;
    std::vector<int> arr;
};

struct mergesort {
    int n;
    void init(std::vector<int>& A) {
        n = A.size();
        _mergesort(A, 0, n-1);
    }

    void _mergesort(std::vector<int>& A, int p, int r) {
        if (p >= r) 
            return;
        int q = (p+r) >> 1;
        _mergesort(A ,p, q);
        _mergesort(A, q+1, r);
        merge(A, p, q, r);
    }

    void merge(std::vector<int>& A, int p ,int q, int r) {
        int nl = q - p + 1;
        int nr = r - q;
        std::vector<int> L(nl), R(nr);
        for (int i = 0; i < nl; i++) {
            L[i] = A[p+i];
        }
        for (int j = 0 ; j < nr; j++) {
            R[j] = A[q+j+1];
        }
        int i = 0, j = 0, k = p;
        while (i < nl && j < nr) {
            if (L[i] <= R[j]) {
                A[k] = L[i]; 
                i++;
            } else {
                A[k] = R[j];
                j++;
            }
            k++;
        }
        while (i < nl) {
            A[k++] = L[i++];
        }
        while (j < nr) {
            A[k++] = R[j++];
        }

    }
};

#endif ALGORITHMS_MERGESORT_H_