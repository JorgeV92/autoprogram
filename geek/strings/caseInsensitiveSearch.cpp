#include <iostream>
#include <vector>
#include <string>
#include <string_view>
#include <algorithm>

using namespace std; 

vector<int> computeLPSArray(string_view pat) {
    int n = pat.size();
    vector<int> lps(n,0);
    int len = 0 ;
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

vector<int> search(string& pat, string& txt) {
    transform(txt.begin(), txt.end(), txt.begin() , 
            [](unsigned char c) {
                return tolower(c);
            });
    transform(pat.begin(), pat.end(), pat.begin() ,
                [](unsigned char c) {
                    return tolower(c);
                });

    int n = txt.size();
    int m = pat.size();

    vector<int> lps = computeLPSArray(pat);
    vector<int> out;
    int i = 0, j = 0;
    while (i < n) {
        if (txt[i] == pat[j]) {
            i++;
            j++;

            if (j == m) {
                out.push_back(i- j);
                j = lps[j-1];
            }
        } else {
            if (j != 0) {
                j = lps[j-1];
            } else {
                i++;
            }
        }
    }
    return out;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string txt = "aBcAb";
    string pat = "aB";

    vector<int> res = search(pat, txt);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";

        
    return 0;
}