#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    x--, y--;
    vector<int> in, out; // a is out b is in
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        if (i <= x || i > y) out.push_back(v);
        else in.push_back(v);
    }

    if (!in.empty())  {
        rotate(in.begin(), min_element(in.begin(), in.end()), in.end());
    }
    int m = in.empty() ? -1 : in[0];
    auto it = out.begin();
    while (it != out.end() && *it < m) it++;
    out.insert(it, in.begin(), in.end());
    for (int i = 0; i < n; i++) {
        cout << out[i] << " \n"[i == n-1];
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