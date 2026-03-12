#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
#include <cstring>

using namespace std;

constexpr int N = 105;

vector<int> e[N];
int color[N];
vector<bool> vis;
stack<int> stk;

void dfs(int v) {
    if (!color[v]) {
        color[v] = 1;
        for (int u : e[v]) {
            dfs(u);
        }
        color[v] = 2;
        stk.push(v);
    } else if (color[v] == 1) {
        cout << "Impossible\n";
        exit(0);
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    int k, m;
    for (int i = 1; i < n; i++) {
        k = 0;
        m = min(s[i].length(), s[i-1].length());
        for (int j =0 ;j < m; j++) {
            if (s[i][j] != s[i-1][j]) {
                k = 1;
                e[s[i-1][j]-'a'].push_back(s[i][j]-'a');
                break;
            }
        }

        if (!k) {
            if (s[i].length() < s[i-1].length()) {
                cout << "Impossible\n";
                return 0;
            }
        }
    }

    vis.assign(n, false);
    memset(color, 0, sizeof(color));

    for (int i = 0; i < 26; i++) {
        if (!color[i]) {
            dfs(i);
        }
    }

    while (!stk.empty()) {
        cout << (char)(stk.top()+'a');
        stk.pop();
    }

    return 0;
}