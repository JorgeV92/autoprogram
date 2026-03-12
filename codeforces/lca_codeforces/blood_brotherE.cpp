#include <iostream>
#include <vector>

using namespace std;

struct LCA {
    int N; vector<vector<int>> up; vector<int> p;
    void init(int _N, vector<int>& parent) {
        N = _N;
        int d = 1;
        while ((1 << d) <= N) d++;
        up.assign(d, vector<int>(N));
        p = vector<int>(parent.begin(), parent.end());
    } 

    void gen() {
        for (int i = 1; i < N; i++) {
            up[0][i] = p[i];
        }

        for (int j = 1; j < up.size(); j++) {
            for (int v = 1;  v < N; v++) {
                up[j][v] = up[j-1][up[j-1][v]];
            }
        }
    }

    int go_up(int x, int k) {
        for (int j = 0; j < up.size(); j++) {
            if (k & (1 << j)) {
                x = up[j][x];
            }
        }
        return x;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> parent(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> parent[i];
    }
    
    LCA tree;
    tree.init(n+1, parent);

    int t;
    cin >> t;

    while (t--) {
        int v, k;
        cin >> v >> k;
        cout << tree.go_up(v, k) << " ";
    }
    cout << endl;

    return 0;
}
