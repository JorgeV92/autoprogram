#include <iostream>
#include <vector>
#include <cstring>

using namespace std; 

constexpr int MAXN = 1e5+7;
int deg[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n , m; 
    cin >> n >> m;
    memset(deg, 0, sizeof(deg));
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        deg[b]++;
        deg[a]++;
    }
    int cnt1 = 0;
    int cnt2 = 0;
    int cent = 0;
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 1) cnt1++;
        if (deg[i] == 2) cnt2++;
        if (deg[i] == n-1) cent++;
    }
    if (m == n-1 && cent == 1 && cnt1 == n-1) {
        cout << "star topology\n";
    } else if (m == n -1 && cnt1 == 2 && cnt2 == n-2) {
        cout << "bus topology\n";
    } else if (m == n && cnt2 == n) {
        cout << "ring topology\n";
    } else {
        cout << "unknown topology\n";
    }

    return 0;   
}