#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    set<int> alive; 
    for (int i = 0 ;i < n; i++) {
        alive.insert(i);
    }

    vector<int> ans(n, -1);
    for (int i = 0; i < m; i++) {
        int l ,r, x;
        cin >> l >> r >> x;
        l--, r--, x--;
        auto it = alive.lower_bound(l);
        vector<int> remove;
        while (it != alive.end()) {
            int k1 = *it;
            if (k1 > r) 
                break;
            if (k1 != x) {
                remove.push_back(k1);
                ans[k1] = x;
            }
            it++;
        }

        for (int j = 0; j < (int)remove.size(); j++) {
            alive.erase(remove[j]);
        }
    }

    for (int i =0 ; i < n; i++) { 
        cout << (ans[i] == -1 ? 0 : ans[i] + 1) << " \n"[i+1==n];
    }

    return 0; 
}