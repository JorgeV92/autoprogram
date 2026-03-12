#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    
    vector<int> p(n+1);
    for (int i = 2; i <= n; i++) {
        cin >> p[i];
    }

    vector<int> path;
    for (int v = n; v != 1; v = p[v]) {
        path.push_back(v);
    }
    path.push_back(1);
    reverse(path.begin(), path.end());
    for (int i = 0; i < path.size(); i++) {
        cout << path[i] << " \n"[i+1==path.size()];
    }

    return 0;
}
