#include <iostream>
#include <vector>

using namespace std;

int minimumFibonacciTerms(int k) {
    vector<int> fib{1,1};
    while (fib.back() < k) {
        fib.push_back(fib[fib.size() - 1] + 
                    fib[fib.size() - 2]); 
    }
    int cnt = 0;
    for (int i = fib.size() - 1; i >= 0 && k > 0; i--) {
        while (k >= fib[i]) {
            k -= fib[i];
            cnt++;
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k = 7;
    cout << minimumFibonacciTerms(k) << endl;
    return 0;
}