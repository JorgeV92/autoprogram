#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    map<char, int> cnt;
    for (auto c : s) {
        cnt[c]++;
    }

    auto is_possible = [&](char cur) {
        char mode = cur;
        int space = 0;
        for (auto& [ch, k] : cnt) {
            if (k > cnt[mode]) {
                mode = ch;
            }
            space += k;
        }
        return (cnt[mode] <= (space + 1) / 2) && (cnt[cur] <= space / 2);
    };

    string ans = "";
    char last = '\0';
    for (int i = 0; i < n; i++) {
        for (char j = 'A'; j <= 'Z'; j++) {
            if (cnt[j] == 0 || last == j) 
                continue;
            cnt[j]--;
            if (is_possible(j)) {
                ans.push_back(j);
                last = j;
                break;
            } else {
                cnt[j]++;
            }
        }
    }

    if ((int)ans.size() == n) {
        cout << ans << '\n'; 
    } else {
        cout << "-1\n";
    }
    
    return 0;
}