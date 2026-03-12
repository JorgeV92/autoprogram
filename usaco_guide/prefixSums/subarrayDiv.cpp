#include <iostream>
#include <vector>
#include <map>

using namespace std; 

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<ll> prefix(n+1);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        prefix[i] = prefix[i-1] + x;
    }
    map<ll, ll> mp;
    for (int i = 0; i <= n; i++) {
        mp[(prefix[i] % n + n) % n]++;
    }
    ll cnt = 0;
    for (const auto& [_, f] : mp) {
        cnt += f * (f-1) / 2;
    }

    cout << cnt << endl;

    return 0;
}