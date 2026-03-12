#include <iostream>
#include <vector>
#include <map>

using namespace std; 

#define ll long long 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, X;
    cin >> n >> X;
    vector<int> A(n);
    for (int i =0 ;i < n; i++) {
        cin >> A[i];
    }
    int l = 0, r = -1;
    ll sum = 0;
    ll cnt = 0;
    while (r < n) {
        while (r < n && sum < X) {
            sum += A[++r];
        }
        while (l <= r && sum > X) {
            sum -= A[l++];
        }
        if (sum == X) {
            cnt++;
            sum -= A[l++];
        }
    }

    cout << cnt << endl;

    return 0;
}