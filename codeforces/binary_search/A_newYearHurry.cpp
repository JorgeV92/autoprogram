#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; 
    cin >> n >> k;
    int t = 240 - k;
    int l = 0, r = n;
    while (l < r) {
        int mid = l + (r-l + 1) / 2;
        if ((5 * (mid *(mid+1)/2))  > t) {
            r = mid - 1;
        } else {
            l = mid;
        }
    }
    cout << l << '\n';
}