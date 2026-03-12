#include <iostream>
#include <vector>
#include <iterator>
#include <utility>

using namespace std;

void selectionSort(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n-1; i++) {
        int k = i;
        for (int j = i+1; j < n; j++) {
            if (a[j] < a[k]) {
                k = j;
            }
        }
        swap(a[i], a[k]);
    }
}

void selectionSort(int a[], const int sz) {
    for (int i = 0; i < sz-1; i++) {
        int mn = i;
        for (int j = i+1; j < sz; j++) {
            if (a[j] < a[mn]) {
                mn = j;
            }
        }
        swap(a[i], a[mn]);
    }
}

int main() {
    int a[] = {30, 50, 20, 10, 40};
    constexpr int n = static_cast<int>(size(a));
    selectionSort(a, n);
    for (int x : a) {
        cout << x << " ";
    }
    cout << endl;
    vector<int> arr{4, 6, 22, 1, 32, 3, 88, 9};
    selectionSort(arr);
    for (int x  : arr)  {
        cout << x << " ";
    }
    cout << endl;
}