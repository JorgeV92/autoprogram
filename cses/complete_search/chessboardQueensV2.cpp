#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std; 

const int N = 8;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> B(N);
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    vector<int> queens(N);
    int ways = 0;

    iota(queens.begin(), queens.end(), 0);

    do {
        bool valid = true;
        for (int c = 0; c < N; c++) {
            if (B[queens[c]][c] == '*') {
                valid = false;
                break;
            }
        }

        vector<bool> taken(N*2-1);
        for (int c = 0; c < N; c++) {
            if (taken[c + queens[c]]) {
                valid = false;
                break;
            }
            taken[c+queens[c]] = true;
        }

        taken = vector<bool>(N*2-1);
        for (int c = 0; c < N; c++) {
            if (taken[queens[c] - c + N -1]) {
                valid = false;
                break;
            }
            taken[queens[c] - c + N - 1] = true;
        }
        if (valid) ways++;

    } while(next_permutation(queens.begin(), queens.end()));

    cout << ways << endl;

    return 0;
}