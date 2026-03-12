#include <iostream>
#include <vector>
#include <cstdint>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    int64_t sum = (n * 1LL * (n+1)) / 2;
    if (sum % 2 == 0) {
        sum = sum / 2;
        set<int> s1, s2;
        for (int i = n; i >= 1; i--) {
            if (sum > 0 && i <= sum) {
                s1.insert(i);
                sum -= i;
            } else {
                s2.insert(i);
            }
        }
        cout << "YES\n";
        cout << (int)s1.size() << '\n';
        for (auto x : s1) {
            cout << x << " ";
        }
        cout << '\n';
        cout << (int)s2.size() << '\n';
        for (auto x : s2) {
            cout << x << ' ';
        }
        cout << '\n';
    } else {
        cout << "NO\n";
    }
    return 0;
}