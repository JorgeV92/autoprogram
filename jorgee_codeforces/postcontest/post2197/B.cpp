#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<int, int> pos;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            pos[a] = i;
        }

        int lst = -1;
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        for (int i = 0; i < n; i++) {
            if (lst > pos[b[i]]) {
                cout << "NO\n";
                goto end;
            } 
            lst = pos[b[i]];

        }
        cout << "YES\n";  
    end:;
    }
    return 0;
}