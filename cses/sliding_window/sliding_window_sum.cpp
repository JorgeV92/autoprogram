#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


int main() {
    int n, k;
    cin >> n >> k;
    
    int x, a, b, c;
    cin >> x >> a >> b >> c;

    vector<long long> arr;

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            arr.push_back(x);
            continue;
        }
        
        long long val = (a * arr.back() + b) % c;
        arr.push_back(val);
    }

    auto print_arr = [&](vector<int>& A) {
        for (int x : A) {
            cout << x << " ";
        }
        cout << endl;
    };

    int l = 0, r =0;
    vector<long long> sums;
    long long sum = 0;
    while (r <= n) {
        if ((r -l + 1) > k) {
            sums.push_back(sum);
            sum -= arr[l++];
        }
        sum += arr[r++];
    }   

   //  print_arr(sums);

    long long total = 0;
    for (long long v : sums) {
        total ^= v;
    }

    cout << total << endl;

    return 0;
}
