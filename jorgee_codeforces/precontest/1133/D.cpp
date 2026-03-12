#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>

using namespace std;

#define f first
#define s second

void norm(pair<int, int>& p) {
    if (p.f < 0) {
        p.f *= -1;
        p.s *= -1;
    } else if (p.f == 0 && p.s < 0) {
        p.s *= -1;
    } 
    int d = gcd(abs(p.f), abs(p.s));
    p.f /= d;
    p.s /= d;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) 
        cin >> a[i];
    for (int i = 0; i < n; i++) 
        cin >> b[i];

    map<pair<int,int>, int> mp;
    int ans = 0;
    int cnt =0 ;
    for (int i =0 ;i < n; i++) {
        if (a[i] == 0) {
            if (b[i] ==0) 
                cnt++;
        } else {
            auto p = make_pair(-b[i], a[i]);
            norm(p);
            mp[p]++;
            ans = max(ans, mp[p]);
        }
    }

    cout << ans + cnt << endl;

    return 0;
}