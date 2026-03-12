#include <iostream>
#include <vector>

using namespace std; 

int firstMissingPositive(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        while (arr[i] >= 1 && arr[i] <= n && arr[i] != arr[arr[i] - 1])
            swap(arr[i], arr[arr[i]-1]);
    }

    for (int i = 1; i <= n; i++) {
        if (arr[i-1] != i) 
            return i;
    }

    return n+1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie( nullptr);
    
    return 0;
}