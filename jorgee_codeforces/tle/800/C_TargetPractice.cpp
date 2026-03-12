#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> mat {
    {1,1,1,1,1,1,1,1,1,1},
    {1,2,2,2,2,2,2,2,2,1},
    {1,2,3,3,3,3,3,3,2,1},
    {1,2,3,4,4,4,4,3,2,1},
    {1,2,3,4,5,5,4,3,2,1},
    {1,2,3,4,5,5,4,3,2,1},
    {1,2,3,4,4,4,4,3,2,1},
    {1,2,3,3,3,3,3,3,2,1},
    {1,2,2,2,2,2,2,2,2,1},
    {1,1,1,1,1,1,1,1,1,1},  
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int ans = 0;
        for (int r = 0; r < 10; r++) {
            string row;
            cin >> row;
            for (int c = 0; c < row.size(); c++) {
                if (row[c] == 'X') {
                    ans += mat[r][c];
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}