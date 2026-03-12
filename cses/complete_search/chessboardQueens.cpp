#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std; 

const int N = 8;
bool col[N], diag[N*2-1], anti[N*2-1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> B(N);
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }
    int ways = 0;

    auto search = [&](auto&& self, int r) {
        if (r == N) {
            ways++;
            return;
        }
        for (int c = 0; c < N; c++) {
            if (B[r][c] == '*') continue;
            if (col[c] || diag[r+c] || anti[r-c+N-1]) continue;
            col[c] = diag[r+c] =  anti[r-c+N-1] =true;
            self(self, r+1);
            col[c] = diag[r+c] = anti[r-c+N-1] = false;
        }
    };
    
    search(search, 0);
    cout << ways << endl;

    return 0;
}