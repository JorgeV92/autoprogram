#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> prefix_function(vector<int>& pat) {
    int n = pat.size();
    vector<int> lps(n, 0);
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

vector<int> search(vector<int>& a, vector<int>& b) {
    int n = a.size();
    int m = b.size();
    vector<int> lps = prefix_function(b);
    int i = 0, j = 0;
    vector<int> out;
    while (i < n) {
        if (a[i] == b[j]) {
            i++;
            j++;
            if (j == m) {
                out.push_back(i-j);
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

    vector<int> a = {2, 3, 0, 3, 0, 3, 0};
    vector<int> b = {3, 0, 3, 0};
  
    vector<int> res = search(a, b);
    for(int idx: res)
        cout << idx << " ";
        
    return 0;
}