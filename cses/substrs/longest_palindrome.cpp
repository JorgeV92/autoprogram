#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct manacher {
    vector<int> p;
    string org;
    string ms;
    
    void init(string& s) {
        ms = "@";
        org = string(s);
        for (char c : s ) {
            ms += "#";
            ms += c;
        }
        ms += "#$";
        gen();
    }

    void gen() {
        int n = ms.size();
        int l = 0, r = 0;
        p.assign(n, 0);
        for (int i = 1; i < n-1; i++ ) {
            int mirror = r + l - i;
            if (mirror >= 0 && mirror < n)
                p[i] = max(0, min(r-i, p[mirror]));
            
            while (ms[i+1+p[i]] == ms[i-1-p[i]]) {
                ++p[i];
            }

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

    bool check(int l, int r) {
        int len = r - l + 1;
        int center = (r+l) / 2;
        int is_odd = len & 1;
        return len <= get_longest(center, is_odd);
    }

    string get_longest_string() {
        int n = org.size(), max_len = 1, start = 0;
        
        for (int i = 0; i < n; i++) {
            int odd_len = get_longest(i, 1);
            if (odd_len > max_len) {
                start = i - (odd_len - 1) / 2;
            }

            int even_len = get_longest(i, 0);
            if (even_len > max_len) {
                start = i - (even_len - 1) / 2;
            }
            max_len = max(max_len, max(odd_len, even_len));
        }

        return org.substr(start, max_len);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s; 
    cin >> s;

    manacher ma;
    ma.init(s);
    cout << ma.get_longest_string() << endl;
}