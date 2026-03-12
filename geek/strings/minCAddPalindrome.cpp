#include <iostream>
#include <vector>
#include <string>
#include <string_view>
#include <algorithm>

using namespace std; 

vector<int> prefix_function(string_view pat) {
    int n = pat.size();
    vector<int> lps(n,0);
    int len = 0;
    int i = 1;
    while (i < n) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len-1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

 int minChar(string &s) {
    string rev = s;
    reverse(rev.begin(), rev.end());
    string pat = s + '$' + rev;
    vector<int> lps = prefix_function(pat);
    return (s.size() - lps.back());
 }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s = "aacecaaaa";
    cout << minChar(s);
    
    return 0;
}