#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*

    Given a string s, find the total number of palindromic substrings of 
    length greater than or equal to 2 present in the string.

    A substring is palindromic if it reads the same forwards and backwards.

*/

// Using Center Expansion 
// O(n^2) time
// O(1) space


int count_palindromes(string& s) {
    int n = s.size();
    int count = 0;

    // ODD
    for (int i = 0; i < s.size(); i++) {
        int l = i-1;
        int r = i+1;
        while (l >= 0 && r < n) {
            if (s[l] == s[r]) {
                count++;
            } else 
                break;
            l--; r++;
        }
    }

    // EVEN
    for (int i = 0; i < s.size(); i++) {
        int l = i;
        int r = i+1;
        while (l >= 0 && r < n) {
            if (s[l] == s[r]) {
                count++;
            } else 
                break;
            l--; r++;
        }
    }
    return count;
}

// 

// Manacher's Algorithm
// Time O(n)
// Space O(n)

struct manacher {
    vector<int> p;
    string ms;
    string org;
    void init(string &s) {
        org = s;
        ms = "@";
        for (char c : s) {
            ms += "#";
            ms += c;
        }
        ms += "#$";
        gen();
    }

    void gen() {
        int n = ms.size();
        p.assign(n, 0);
        int l = 0, r = 0;
        for (int i = 1; i < n-1; i++) {
            int mirror = r + l - i;
            p[i] = max(0, min(r-i, p[mirror]));

            while (ms[i+1+p[i]] == ms[i-1-p[i]]) {
                ++p[i];
            }

            if (i + p[i] > r) {
                l = i -p[i];
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
        int center = (r + l) / 2;
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

int count_ps_manacher(string& s) {
    manacher ma;
    ma.init(s);
    int total = 0;

    for (int i = 0; i < ma.p.size(); i++) {
        total += (ma.p[i] + 1) / 2;
    }
    return total - s.length();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // string s = "abbaeae";
    // cout << count_ps_manacher(s) << endl;

    string s = "forgeeksskeegfor";
    manacher ma;
    ma.init(s);
    cout <<  ma.get_longest_string() << endl;

    return 0;
}