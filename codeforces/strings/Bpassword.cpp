#include <iostream>
#include <vector>
#include <string>
#include <string_view>

using namespace std;

vector<int> z_function(const string& s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i < r) {
            z[i] = min(r-i, z[i-l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i+z[i]])
            z[i]++;
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();
    if (s.size() == 1) {
        cout << "Just a legend\n";
    } else {
        vector<int> z = z_function(s);
        vector<int> nzf, vec;
        for (int i = 0; i < n; i++) {
            if (z[i] == n-i) {
                vec.push_back(n-i);
                nzf.push_back(z[i]-1);
            } else {
                nzf.push_back(z[i]);
            }
        }

        sort(nzf.rbegin(), nzf.rend());
        vec.push_back(-1);
        sort(vec.begin(), vec.end());
        for (auto x : nzf) {
            int k = upper_bound(vec.begin(), vec.end(), x) - vec.begin();
            if (vec[k-1] > 0) {
                cout << s.substr(0, vec[k-1]) << '\n'; 
                goto end;
            }
        }
    }
    cout << "Just a legend"\n;

    end:;
    return 0;
}