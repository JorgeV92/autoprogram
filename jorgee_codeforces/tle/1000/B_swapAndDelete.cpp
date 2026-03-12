#include <iostream>
#include <vector>
#include <string>

using namespace std; 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        string s;
        cin >> s;
        int cnt0 = 0, cnt1 = 0;
        for (int i = 0 ; i < (int)s.size(); i++) {
            if (s[i] == '0') cnt0++;
            if (s[i] == '1') cnt1++;
        }
        int t_len = 0;
        for (int i = 0 ;i < (int)s.size(); i++) {
            if (s[i] == '0' && cnt1 > 0) {
                t_len++;
                cnt1--;
            } else if (s[i] == '1' && cnt0 > 0) {
                t_len++;
                cnt0--;
            } else {
                break;
            }
        }
        cout << (int)s.size() - t_len << '\n'; 
    }
    return 0;   
}