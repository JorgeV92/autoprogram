#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    int cnt = 0;
    int b[] = {100, 20, 10, 5, 1};
    for (int x : b) {
        cnt += n/x;
        n %= x;
    }
    cout << cnt << '\n';
    return 0;   
}