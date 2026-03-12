#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    int cnt = 0;
    int i = 0;
    while (i < n && cnt + A[i] <= x) {
        cnt += A[i];
        i++;
    }
    cout << i << endl;

    return 0;
}