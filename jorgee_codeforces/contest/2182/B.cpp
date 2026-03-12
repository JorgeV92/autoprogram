#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        
        auto calc = [&](int c1, int c2) {
            int l = 0;
            int sz = 1;
            while (true) {
                if (l%2 == 0) {
                    if (c1 >= sz) {
                        c1 -= sz;
                    }  else {
                        break;
                    }
                } else {
                    if (c2 >= sz) {
                        c2 -= sz;
                    } else {
                        break;
                    }
                }
                l++;
                sz <<= 1;
            }
            return l;
        };

        int f = calc(a, b);
        int s = calc(b, a);
        cout << max(f, s) << endl;
    }
    return 0;
}