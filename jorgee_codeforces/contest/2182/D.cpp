#include <iostream>
#include <vector>

using namespace std; 

const int MOD = 998244353;

void addi(int& a, int b) {
    a += b;
    if (a >= MOD) {
        a -= MOD;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n; 
        cin >> n;
        vector<int> a(n+1);
        for (int i = 0; i <= n; i++) {
            cin >> a[i];
        }
        int ans = 0;
        auto dfs = [&](auto&& dfs, int ii) {
            if (ii == n) {
                return;
            }
            
        }
    }
    return 0;
}