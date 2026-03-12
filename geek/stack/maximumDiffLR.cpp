#include <iostream>
#include <vector>
#include <stack>
#include <cstring>

using namespace std; 

void findMaxDiff(vector<int> &arr) {
    int n = arr.size();
    int l[n+1];
    int r[n+1];
    memset(l, 0, sizeof(l));
    memset(r, 0, sizeof(r));

    arr.push_back(0);
    stack<int> stk;
    stk.push(0);

    for (int i = 0; i < n; i++) {
        while (!stk.empty() && arr[stk.top()] >= arr[i]) {
            stk.pop();
        }
        if (!stk.empty()) 
            l[i] = stk.top();
        stk.push(i);
    }

    while (!stk.empty()) stk.pop();

    for (int i = n-1; i >= 0; i--) {
        while (!stk.empty() && arr[stk.top()] >= arr[i]) {
            stk.pop();
        }
        if (!stk.empty()) 
            r[i] = stk.top();
        stk.push(i);
    }

    int mx = 0;
    for (int i = 0; i < n; i++) {
        mx = max(mx, abs(arr[l[i]] - arr[r[i]]));
    }
    cout << mx << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> a{2, 4, 8, 7, 7, 9, 3};
    findMaxDiff(a);

    return 0;
}