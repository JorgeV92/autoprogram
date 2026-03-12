#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj; 

void solve() {
    int n, m;
    cin >> n >> m;
    adj = vector<vector<int>>(n);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int a;
            cin >> a;
            adj[i].push_back(a);        
        } 
    } 
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}