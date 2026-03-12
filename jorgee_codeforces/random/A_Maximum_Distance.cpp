#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> X(n), Y(n);
    for (int i = 0; i < n; i++) {
        cin >> X[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> Y[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j=i+1; j < n; j++) {
            int e = pow((X[i] - X[j]), 2) + pow((Y[i] - Y[j]),2);
            ans = max(ans, e);
        }
    }
    cout << ans << endl;
} 