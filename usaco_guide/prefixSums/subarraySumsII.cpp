#include <iostream>
#include <vector>
#include <map>

using namespace std; 

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, X;
    cin >> N >> X;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    map<ll, int> mp;
    ll sum = 0;
    ll ans = 0;
    mp[0] = 1;
    for (int x  : A) {
        sum += x;
        ans += mp[sum-X];
        mp[sum]++;
    }
    cout << ans << endl;
    return 0;
}