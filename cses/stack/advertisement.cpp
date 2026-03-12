#include <iostream>
#include <vector>
#include <stack>

using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<ll> a(n+1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    a.push_back(-1);
    stack<ll> stk;
    stk.push(-1);

    ll ans = 0;
    for (int i = 0; i <= n; i++) {
        while (stk.top() != -1 && a[stk.top()] >= a[i]) {
            int x = stk.top();
            stk.pop();
            ll area = (i-1-stk.top()) * a[x];
            if (ans < area) ans = area;
        }
        stk.push(i);
    }
    cout << ans << endl;


    return 0;
}