#include <iostream>
#include <vector>
#include <string>

using namespace std; 

void solve() {
    int n; 
    cin >> n;
    long long ans =0;

    auto dig_sum = [&](int nn) {
        string s = to_string(nn);
        long long sum = 0;
        for (char c : s) {
            sum += c - '0';
        }
        return sum;
    };

    for (int i = n; i < n + 200; i++) {
        if (i - dig_sum(i) == n) {
            ans++;
        }
    }
    cout << ans << "\n";
}

void solve2() {
    int n;
    cin >> n;

    auto dig_sum = [&](int x) {
        long long sum = 0;
        while (x) {
            sum += x%10;
            x /= 10;
        }
        return sum;
    };
    int ans = 0;
    for (int i = n; i <=(n+1000); i++) {
        if (i - dig_sum(i))  
            ans++;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
