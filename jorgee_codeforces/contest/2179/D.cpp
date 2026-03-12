#include <iostream>
#include <vector>
#include <bit>
#include<numeric>

using namespace std; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n; 
        cin >> n;
        int N = (1 << n);
        vector<bool> used(N, false);
        for (int k = N; k >= 0; k--) {
            int mask = (1 << k) - 1;
            for (int x = 0; x < N; x++){
                if (!used[x] &&(x&mask) == mask ) {
                    cout << x << " ";
                    used[x] = true;
                }
            }
        }
        cout << endl;
    }
    return 0;
}