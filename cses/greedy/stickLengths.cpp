#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

#define ll long long 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> A(n);
    for (int& i : A) {
        cin >> i;
    }
    sort(A.begin(), A.end());
    ll m = A[n/2];
    ll ans = 0;

    for (int x : A) {
        ans += abs(m-x);
    }
    cout << ans << endl;
    return 0;   
}