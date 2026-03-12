#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; 
    cin >> n;
    vector<bool> vis(n+1);
    int p;
    cin >> p;
    for (int i = 0; i < p; i++) {
        int x;
        cin >> x;
        vis[x] = true;
    }
    cin >> p;
    for (int i = 0; i < p; i++) {
        int y;
        cin>> y;
        vis[y] = true;
    }
    bool valid = true;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            valid = false;
        }
    }
    if (valid) {
        cout << "I become the guy.\n";
    } else {
        cout << "Oh, my keyboard!\n";
    }

    return 0;
}