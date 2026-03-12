#include <iostream>
#include <vector>

using namespace std;

 bool canJumpDP(vector<int>& A) {
    const int n = A.size();
    vector<int> vis(n, -1);
    vis[n-1] = 1;
    for (int i = n-1; i >= 0; i--) {
        int far = min(i + A[i], n-1);
        for (int j = i+1; j <= far; j++) {
            if (vis[j]) {
                vis[i] = 1;
                break;
            }
        }
    }

    return vis[0] == 1;
 }

bool canJumpGreedy(vector<int>& a) {
    int n = a.size();
    int max_reach = 0;
    for (int i = 0; i < n; i++) {
        if (i > max_reach) return false;
        max_reach = max(max_reach, i + a[i]);
        if (max_reach >= n-1) {
            return true;
        }
    }
    return false;
}

int main() {

    return 0;
}