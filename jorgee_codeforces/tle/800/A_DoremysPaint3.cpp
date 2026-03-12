#include <iostream>
#include <vector>
#include <map>

using namespace std; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n; 
        cin >> n;
        map<int,int> occ;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            occ[x]++;
        }   
        if (occ.size() > 2) {
            cout << "No\n";
        } else {
            if (abs(occ.begin()->second - occ.rbegin()->second) <= 1) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        }
    }
    return 0;
}