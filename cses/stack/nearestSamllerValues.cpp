#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i =0 ; i < n; i++) {
        cin >> a[i];
    }

    stack<int> stk;
    for (int i = 0; i < n; i++) {
        while (!stk.empty() && a[stk.top()] >= a[i] ) {
            stk.pop();
        }
        if (stk.empty()) {
            cout << 0 << " ";
        } else {
            cout << stk.top() + 1 << " ";
        }
        stk.push(i);
    }
    cout << endl;

    

    return 0;
}