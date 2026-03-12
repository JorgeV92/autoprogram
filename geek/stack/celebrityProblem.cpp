#include <iostream>
#include <vector>
#include <stack>

using namespace std; 

int celebrityAjacency(vector<vector<int>>& mat)  {
    int n = mat.size();
    vector<int> in(n), out(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j]) {
                in[j]++;
                out[i]++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (in[i] == n && out[i] == 1) 
            return i;
    }

    return -1;
}

int celebrityStack(vector<vector<int>>& mat) {
    int n = mat.size();
    stack<int> stk;
    for (int i = 0; i < n; i++) 
        stk.push(i);
    while (stk.size() > 1) {
        int A = stk.top();
        stk.pop();
        int B = stk.top();
        stk.pop();
        if (mat[A][B]) {
            stk.push(B);
        } else {
            stk.push(A);
        }
    }

    int C = stk.top();
    stk.pop();

    for (int i = 0; i < n; i++) {
        if (i == C) continue;
        if (mat[C][i] || !mat[i][C])
            return -1;
    }

    return C;
}

int celebrityTwoPointers(vector<vector<int>>& mat) {
    int n = mat.size();
    int i = 0, j = n-1;
    while (i < j) {
        if (mat[i][j]) {
            j--;
        } else {
            i++;
        }
    }

    int C = i;
    for (int i =  0; i < n; i++) {
        if (C == i) continue;
        if (mat[C][i] || !mat[i][C])
            return -1;
    }
    return C;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}