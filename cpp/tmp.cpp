#include <iostream>
#include <string>

using namespace std;

string reduceDigits(string s) {
    bool changed = true;
    while (changed) {
        changed = false;
        string out;
        for (int i = 0, n = (int)s.size(); i < n; ) {
            int j = i + 1;
            while (j < n && s[j] == s[i]) j++;
            int len = j - i;
            if (len > 1) {
                changed = true;
                int digit = s[i] - '0';
                int run_sum = digit * len;
                out += to_string(run_sum);
            } else {
                out.push_back(s[i]);
            }
            i = j;
        }
        s.swap(out);
    }
    return s;
}

int main() {
    cout << reduceDigits("66644319333") << "\n"; // 26328
}

