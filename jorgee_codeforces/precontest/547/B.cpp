#include <iostream>
#include <vector>
#include <stack>

using namespace std; 

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define ROF(i,a,b) for (int i = (a); i >= (b); i--)

template<class T> inline void smax(T &x, T y) { x = max((x), (y)); }

constexpr int N = 1e6 + 100;
int a[N], l[N], r[N], ans[N];
stack<int> stk;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    FOR(i,0,n) {
        cin >> a[i];
    }

    fill(l, l+N, -1);
    fill(r, r+N, n);

    FOR(i,0,n) {
        // find the index of the first element to the left that is smaller than a[i].
        while (!stk.empty() && a[stk.top()] >= a[i]) {
            stk.pop();
        }
        if (!stk.empty()) 
            l[i] = stk.top();
        stk.push(i);
    }
    while (!stk.empty()) stk.pop();

    ROF(i,n-1,0) {
        // find the index of the first element to the right that is smaller than a[i].
        while (!stk.empty() && a[stk.top()] >= a[i]) {
            stk.pop();
        }
        if (!stk.empty())
            r[i] = stk.top();
        stk.push(i);
    }
    
    FOR(i,0,n) {
        int len = r[i] - l[i] - 1;
        smax(ans[len], a[i]);
    }

    ROF(i,n-1,0) {
        smax(ans[i], ans[i+1]);
    }

    FOR(i, 1, n+1) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}