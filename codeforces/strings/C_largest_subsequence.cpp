#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n ;
        cin >> n;
        string s;
        cin >> s;
        vector<int> a;
        for (int i = n-1; i >= 0; i--) {
            if (a.empty() || s[i] >= s[a.back()])
                a.push_back(i);
        }
        reverse(a.begin(), a.end());
        int j =0;
        while (j < a.size() && s[a[0]] == s[a[j]]) j++;
        int ans = a.size()- j;
        for (int i = 0; i < a.size() - 1 - i; i++) {
            swap(s[a[i]], s[a[a.size() - 1 - i]]);
        }
        if (!is_sorted(s.begin(), s.end())) {
            ans = -1;
        }
        cout << ans << "\n";

    }
    return 0;
}