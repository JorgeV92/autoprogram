#include <iostream>
#include <vector>
#include <string>

using namespace std;

using pii = pair<int,int>;

const int MAXN = 100001;
int m[MAXN];
int z[MAXN];
vector<pii> ans;
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s;
    int n = s.size();
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i < r) {
            z[i] = min(r-i, z[i-l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i+z[i]]) {
            z[i]++;
        }
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    
    z[0] = n;
    for (int i = 0; i < n; i++) 
        m[z[i]]++;
    for (int i = n; i > 0; i--) {
        m[i-1] += m[i];
    } 
    for (int i = 1; i <= n; i++) {
        if (z[n-i] == i) {
            ans.push_back({i, m[i]});
        }
    }
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].first << " " << ans[i].second << '\n';
    }
    
    return 0;
}