#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> minSubsetDiff(int n) {
    vector<vector<int>> out(2);
    int sum1 =0, sum2 = 0;
    int half = n*(n+1) / 4;
    for (int i = n; i >= 1; i--) {
        if (sum1+i <= half) {
            out[0].push_back(i); 
            sum1 += i;
        }  else {
            out[1].push_back(i);
            sum2 += i;
        }
    }
    return out;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    return 0;
}