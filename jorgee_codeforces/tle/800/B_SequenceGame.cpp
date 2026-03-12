#include <iostream>
#include <vector>

using namespace std; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n; 
        cin >> n;
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        vector<int> a{b[0]};
        for (int i = 1; i < n; i++) {
            if (b[i] >= b[i-1]) {
                a.push_back(b[i]);
            } else {
                a.push_back(1);
                a.push_back(b[i]);
            }
        } 
        cout << a.size() << endl;
        for (int i =0 ; i < a.size(); i++) {
            cout << a[i] << " \n"[i+1==a.size()];
        }
    }
    return 0;
}