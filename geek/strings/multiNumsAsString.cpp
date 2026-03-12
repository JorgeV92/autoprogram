#include <iostream>
#include <vector>
#include <string>

using namespace std;

string multiplyStrings(string s1, string s2) {
    int n1 = s1.size(), n2 = s2.size();
    if (n1 == 0 || n2 == 0) return "";
    int nn = 1, mm = 1;
    if (s1[0] == '-')
        nn = -1;
    if (s2[0] == '-')
        mm = -1;
    int isNeg = nn * mm;
    vector<int> res(n1+n2,0);
    int i1 = 0, i2 = 0;
    for (int i = n1-1; i >= 0; i--) {
        if (s1[i] == '-') continue;
        int carry = 0;
        int num1 = s1[i] - '0';
        i2 = 0;
        for (int j = n2-1; j >= 0; j--) {
            int num2 = s2[j] - '0';
            int sum = num1 * num2 + res[i1 + i2] + carry;
            carry = sum /10;
            res[i1+i2] = sum % 10;
            i2++;
        }
        if (carry > 0) 
            res[i1 + i2] += carry;
        i1++;
    }
    int i = res.size() - 1;
    while (i >= 0 && res[i] == 0) i--;
    if (i == -1) return "0";
    string s = "";
    while (i >= 0) 
        s += to_string(res[i--]);
    if (isNeg == -1) 
        s = "-" + s;
    return s;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s1 = "0033", s2 = "2";
    cout << multiplyStrings(s1, s2) << '\n';
    return 0;
}