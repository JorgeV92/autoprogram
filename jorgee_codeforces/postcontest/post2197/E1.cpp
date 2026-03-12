#include<iostream>
#include <vector>

using namespace std; 

vector<int> ask(int k) {
    cout << "? " << k << "\n";
    int l;
    cin >> l;
    if (l == -1) {
        exit(0);
    }
    vector<int> res(l);
    for (int i = 0; i < l; i++) {
        cin >> res[i];
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<pair<int,int>> edges;

    for (int i = 0; i < n; i++) {
        int prev = -1;
        while (true) {
            int l = 1, r = (1 << 30);
            while (l <= r) {
                int m = l + (r - l) / 2;
                auto path = ask(m);
                if (!path.empty() && path[0] < i + 1) {
                    l = m + 1;
                    continue;
                }
                if (path.empty() || path[0] > i + 1 || (path.size() > 1 && path[1] > prev)) {
                    r = m-1;
                } else {
                    l = m + 1;
                }
            }
            auto path = ask(l);
            if (path.size() > 1) {
                edges.emplace_back(path[0], path[1]);
                prev = path[1];
            } else {
                break;
            }
        }
    }
    cout << "! " << edges.size() << '\n';
    for (auto [u, v] : edges) {
        cout << u << ' ' << v << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}