#include <iostream>
#include <vector>
#include <map>

using namespace std; 

#define pii pair<int,int>

void solve(){
    int n;
    cin >> n;
    vector<pii> a(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >>x;
        a[i] = {x, x};
    }
    vector<bool> alive(n);
    bool attacked = true;
    while (true) {
        
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
}