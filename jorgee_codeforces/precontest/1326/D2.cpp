#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct manacher {
    vector<int> p;
    string ms;
    string org;
    
    void init(string& s) {
        ms += '@';
        org = string(s);
        for (char c : s) {
            ms += '#';
            ms += c;
        }
        ms += "#@";
        gen();
    }

    void gen() {
        int n = ms.size();
        p.assign(n, 0);
        int l = 0, r = 0;
        for (int i = 1; i < n; i++) {
            int mirror = r + l - i;
            if (mirror >= 0 && mirror < n) 
                p[i] = max(0, min(r-i, p[mirror]));

            while (ms[i+1+p[i]] == ms[i-1-p[i]]) 
                ++p[i];

            if (i + p[i] > r) {
                l = i - p[i];
                r = i + p[i];
            }
        }
    }

    int get_longest(int cen, int odd) {
        int pos = 2 * cen + 2 + !odd;
        return p[pos];
    }

    int get_longest_string() {
        
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}