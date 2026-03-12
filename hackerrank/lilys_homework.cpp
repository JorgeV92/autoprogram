#include <iostream>
#include <vector>

using namespace std;

vector<pair<int,int>> asc, desc;
vector<bool> vis;

void dfs_asc(int v) {
    if (vis[v]) return;
    vis[v] = true;
    dfs_asc(asc[v].second);
}

void dfs_desc(int v) {
    if (vis[v]) return;
    vis[v] = true;
    dfs_desc(desc[v].second);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    asc.resize(n);
    desc.resize(n);
    vis.assign(n, false);

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        asc[i] = {a[i], i};
        desc[i] = {a[i], i};
    }

    sort(asc.begin(), asc.end());
    sort(desc.begin(), desc.end(), greater<>());
    
    int asc_cycles = 0;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            asc_cycles++;
            dfs_asc(i);
        }
    }

    vis.assign(n, false);
    int desc_cycles = 0;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            desc_cycles++;
            dfs_desc(i);
        }
    }

    cout << min(n - asc_cycles, n - desc_cycles);

}