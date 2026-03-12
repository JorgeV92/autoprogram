#include <iostream>
#include <vector>

using namespace std;

int minJumps(vector<int>& arr ){
    int n = arr.size();
    if (arr[0] ==0) 
        return 0;
    int maxReach = 0;
    int curReach = 0;
    int jumps = 0;
    for (int i = 0; i < n; i++) {
        maxReach = max(maxReach, i + arr[i]);
        if (maxReach >= n-1) {
            return jumps + 1;
        }
        if (i == curReach) {
            if (maxReach == i) {
                return -1;
            } else {
                jumps++;
                curReach = maxReach;
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    return 0;
}