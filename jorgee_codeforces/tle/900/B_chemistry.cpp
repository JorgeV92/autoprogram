#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> freq(26);
        for (char c : s) {
            freq[c-'a']++;
        }
        int odd = 0;
        for (int x : freq) {
            if ((x&1))
                odd++;
        }
        if (odd > k + 1) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }

    }
    return 0;   
}