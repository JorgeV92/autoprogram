#include <iostream>
#include <map>

using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;
    
    map<ll,ll> mp;

    while (Q--) {
        int t; 
        ll k, v;
        cin >> t;
        if (t) {
            cin >> k;
            if (mp.count(k)) {
                cout << mp[k] << endl;
            } else {
                cout << 0 << endl;
            }
        } else {
            cin >> k >> v;
            mp[k] = v;
        }
    }

    return 0;   
}