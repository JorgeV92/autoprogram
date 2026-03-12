#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    string A;
    cin >> A;

    string wrong = "WRONGANSWER";
    unordered_map<char, int> freq;
    for (int i = 0; i < n; i++) {
        freq[A[i]]++;
    }
    char least = 'a';
    for (char c = 'a'; c <= 'z'; c++) {
        if (freq[c] < freq[least]) {
            least = c;
        }
    }

    if (freq[least] > k || k > n) {
        cout << wrong << endl;
        return 0;
    }

    string res;
    k -= freq[least];
    for (int i = 0; i < n; i++) {
        if (least == A[i]) {
            res.push_back(A[i]);
        } else if (k > 0) {
            res.push_back(A[i]);
            k -=1;
        } else {
            res.push_back(least);
        }
    }

    cout << res << endl;
    return 0;
}