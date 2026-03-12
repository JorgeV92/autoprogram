#include <iostream>
#include <vector>
#include <string>
 
using namespace std;
 
 
int main() {
 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
 
    /*
        scanning from left to right
 
        ATTCGGGA
    */
 
    string s;
    cin >> s;
 
    int curr_sz = 1;
    int mx_subs = 0;
 
    for (int  i = 0; i < s.size(); i++) {
       if (i + 1 < s.size())  {
            if (s[i] == s[i+1]) {
            curr_sz += 1;
            } else {
                mx_subs = max(mx_subs, curr_sz);
                curr_sz = 1;
            }
        }
    }
    mx_subs = max(mx_subs, curr_sz);
    cout << mx_subs << endl;
 
    return 0;

}
