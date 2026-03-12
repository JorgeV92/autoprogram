#include <iostream>
#include <vector>

using namespace std;


// 1186. Maximum Subarray Sum with One Deletion 
//
//

// remove unique elements in array 
// sort(A.begin(), A.end())
// A.resize(unique(A.begin(), A.end()) - A.begin()); 
// A.erase(unique(A.begin(), A.end()), A.end());

void kadane(vector<int>& arr) {
    int curr_sum = arr[0];
    int total_max = arr[0];

    for (int i = 1; i < arr.size(); i++) {
        curr_sum = max(arr[i], curr_sum + arr[i]);
        total_max = max(total_max, curr_sum);
    }
    cout << total_max;
}

int maximumSum(vector<int>& arr) {
    const int n = arr.size();
    int total_max = arr[0];
    int suf_no_del = arr[0];
    int suf_del = 0;
    
    for (int i = 1; i < n; i++) {
        suf_del = max(suf_del + arr[i], suf_no_del);
        suf_no_del = max(suf_no_del + arr[i], arr[i]);
        total_max = max({total_max, suf_del, suf_no_del});
    }     

    return total_max;
}



int main() {

    return 0;
}
