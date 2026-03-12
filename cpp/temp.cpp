#include <iostream>
#include <vector>
#include <string>

using namespace std;

void replace() {
    string s = "66644319333";
    string ans;
    int n = s.size();
    bool replaced = true;
    while (replaced) {
        replaced = false;
        string out;
        for (int i = 0; i < s.size();) {
            int j = i + 1;
            while (j < s.size() && s[i] == s[j]) j++;
            int len = j - i;
            if (len > 1) {
                replaced = true;
                int di = s[i] - '0';
                int rs = di * len;
                out += to_string(rs);
            } else {
                out.push_back(s[i]);
            }
            i = j;
        }
        s.swap(out);
    }
    cout << s << endl;
}

int main() {
    replace();
    return 0;
}
