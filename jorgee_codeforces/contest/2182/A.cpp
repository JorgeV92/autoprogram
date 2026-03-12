#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int cost2026 = 2026;
        string t = "2026";
        for (int i = 0; i <= s.size()-4; i++)  {
            int cnt = 0;
            for (int j = 0; j < 4; j++) {
                if (s[i+j] != t[j])
                    cnt++;
            }
            cost2026 = min(cost2026, cnt);
        }
        int cost2025 = 0;
        for (int i = 0; i <= s.size()-4; i++) {
            if (s.substr(i, 4) == "2025") {
                cost2025++;
            }
        }

        cout << min(cost2026, cost2025) << endl;
    }
    return 0;   
}