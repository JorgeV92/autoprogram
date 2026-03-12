#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MAXN = 1500*1500+5;
int trie[MAXN][26];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    string s, t;
    cin >> s >> t;
    cin >> k;

    int id  = 1;
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        int cur = 0;
        int bad = 0;
        for (int j = i; j < s.size(); j++) {
            int idx = s[j]-'a';
            if (t[idx] == '0') 
                bad++;
            if (bad > k) break;
            if (trie[cur][idx] == 0) {
                trie[cur][idx] = id++;
                cnt++;
            }
            cur = trie[cur][idx];
        }
    }

    cout << cnt << '\n';

    return 0;
}