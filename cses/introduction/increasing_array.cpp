#include <iostream>
#include <vector>


using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    /*
        3 2 5 1 7

        3 4 5 6 7

        3 3 5 4 7

        1 + 4  

        A[i-1] and A[i]  
        if A[i] < A[i-1] 
            total operations we need to make the current number
            as large as the previous one is abs(A[i] - A[i-1])


            10
                1000000000 1 1 1 1 1 1 1 1 1
    */

    int n;  
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long min_operations = 0;
    vector<long long> values{arr[0]}; // we dont really need a vector we could just use a variable
    // just update the variable when we encounter a bigger previous value;
    int prev_value = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] </* values.back() */ prev_value) {
            //min_operations += values.back() - arr[i];
            min_operations += prev_value - arr[i];
            // cout << values.back() - arr[i] << endl;
            // values.push_back(values.back());
            continue;
        }
        prev_value = arr[i];
        //  values.push_back(arr[i]);
    
    }

    cout << min_operations << endl;
    

    auto optimal_solution = [&]() {
        int min_op = 0;
        for (int i = 1; i < n; i++) {
            if (arr[i] < arr[i-1]) {
                min_op += arr[i-1] - arr[i];
                arr[i] = arr[i-1];
            }
        }

        cout << min_op << endl;
    };   


    return 0;
}
