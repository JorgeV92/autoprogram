#include <iostream>
#include <vector>

using namespace std; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    vector<int> p(n);
    for (int i =0 ; i< n; i++) {
        int a;
        cin >> a;
        a--;
        p[i] = a;
    }

    for (int i = 0; i < n; i++) {
        if (p[p[p[i]]] == i) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}