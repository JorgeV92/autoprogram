#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <set>

using namespace std;

int primebase(int x) {
    set<int> s;
    for (int i = 2; i*i <= x; i++) {
        while (x % i == 0) {
            s.insert(i);
            x /= i;
        }
    }
    if (x > 1) s.insert(x);
    if (s.size() > 1) return -1;
    if (s.size() == 0) return 1;
    return *s.begin();
}

void euclid() {
    int64_t n;
    cin >> n;
    vector<int64_t> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int64_t> b(n);
    for (int i = 0; i < n; i++) b[i] = primebase(a[i]);
    if (is_sorted(a.begin(), a.end())) {
        cout << "Bob\n";
    } else if (*min_element(b.begin(), b.end()) == -1) {
        cout << "Alice\n";
    } else if (is_sorted(b.begin(), b.end())) {
        cout << "Bob\n";
    } else {
        cout << "Alice\n";
    }

}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        euclid();
    }
    return 0;
}