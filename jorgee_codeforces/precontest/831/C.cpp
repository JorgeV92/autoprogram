#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    cin >> k >> n;
    
    vector<int> arr(k);
    for (int i = 0; i < k; i++) {
        cin >> arr[i];
    }

    vector<long long> prefix(k);
    prefix[0] = arr[0];
    for (int i = 1; i < k; i++) {
        prefix[i] = prefix[i-1] + arr[i];
    }

    vector<int> b(n);
    for (int i = 0; i < n; i++) 
        cin >> b[i];

    set<long long> p;
    for (int i = 0; i < k; i++) {
        long long x = (long long)b[0] - prefix[i];
        p.insert(x);
    }

    int count = 0;
    for (long long x : p) {
        set<long long> g;
        for (int pre : prefix) {
            g.insert(x + pre);
        }
        bool valid = true;
        for (int v : b) {
            if (g.find(v) == g.end()) {
                valid = false;
                break;
            }
        }
        if (valid) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}